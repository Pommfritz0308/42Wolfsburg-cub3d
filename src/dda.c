#include "cub3d.h"

t_point	calc_ray(t_game *game, int x)
{
	t_point	ray_dir;

	game->cam.x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_dir.x = game->dir.x
		+ game->plane.x * game->cam.x;
	ray_dir.y = game->dir.y
		+ game->plane.y * game->cam.x;
	return (ray_dir);
}

void	calc_delta_distance(t_game *game, t_point ray_dir)
{
	game->map.x = floor(game->pos.x);
	game->map.y = floor(game->pos.y);
	if (!ray_dir.x)
		game->d_dist.x = INFINITY;
	else
		game->d_dist.x = fabs(1 / ray_dir.x);
	if (!ray_dir.y)
		game->d_dist.y = INFINITY;
	else
		game->d_dist.y = fabs(1 / ray_dir.y);
}

void	calc_side_distance(t_game *game, t_point ray_dir)
{
	if (ray_dir.x < 0)
	{
		game->step.x = -1;
		game->s_dist.x = (game->pos.x - game->map.x) * game->d_dist.x;
	}
	else
	{
		game->step.x = 1;
		game->s_dist.x = (game->map.x + 1 - game->pos.x) * game->d_dist.x;
	}
	if (ray_dir.y < 0)
	{
		game->step.y = -1;
		game->s_dist.y = (game->pos.y - game->map.y) * game->d_dist.y;
	}
	else
	{
		game->step.y = 1;
		game->s_dist.y = (game->map.y + 1 - game->pos.y) * game->d_dist.y;
	}
}

static void	dda_helper(t_params *data, int x, t_point ray_dir)
{
	double	perp_wall_dist;
	t_game	*g;
	int		y;

	g = &data->game;
	if (g->side == 0)
		perp_wall_dist = (g->s_dist.x - g->d_dist.x);
	else
		perp_wall_dist = (g->s_dist.y - g->d_dist.y);
	g->line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	g->draw_start = -g->line_height / 2 + WINDOW_HEIGHT / 2;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_height / 2 + WINDOW_HEIGHT / 2;
	if (g->draw_end >= WINDOW_HEIGHT)
		g->draw_end = WINDOW_HEIGHT - 1;
	find_hit(data, perp_wall_dist, ray_dir);
	y = 0;
	while (y++ < g->draw_start)
		my_mlx_pixel_put(data->image, x, y, data->config->c_color);
	y = g->draw_end;
	while (y++ < WINDOW_HEIGHT)
		my_mlx_pixel_put(data->image, x, y, data->config->f_color);
	fill_texture_buffer(data, x, ray_dir);
}

void	dda(t_params *data, int x, t_point ray_dir)
{
	t_game	*game;

	game = &data->game;
	while (1)
	{
		if (game->s_dist.x < game->s_dist.y)
		{
			game->s_dist.x += game->d_dist.x;
			game->map.x += game->step.x;
			game->side = 0;
		}
		else
		{
			game->s_dist.y += game->d_dist.y;
			game->map.y += game->step.y;
			game->side = 1;
		}
		if (data->map[(int)game->map.x][(int)game->map.y] == '1')
			break ;
	}
	dda_helper(data, x, ray_dir);
}
