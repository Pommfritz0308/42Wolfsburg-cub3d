#include "cub3d.h"

static t_point	calc_ray(t_game *game, int x)
{
	t_point	ray_dir;

	game->cam.x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_dir.x = game->dir.x
		+ game->plane.x * game->cam.x;
	ray_dir.y = game->dir.y
		+ game->plane.y * game->cam.y;
	return (ray_dir);
}

static void	calc_delta_distance(t_game *game, t_point ray_dir)
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

static void	calc_side_distance(t_game *game, t_point ray_dir)
{
	if (ray_dir.x < 0)
	{
		game->step.x = -1;
		game->s_dist.x = (game->pos.x - game->map.x) * game->d_dist.x;
	}
	else
	{
		game->step.x = 1;
		game->s_dist.x = (game->pos.x - game->map.x + 1) * game->d_dist.x;
	}
	if (ray_dir.y < 0)
	{
		game->step.y = -1;
		game->s_dist.y = (game->pos.y - game->map.y) * game->d_dist.y;
	}
	else
	{
		game->step.y = 1;
		game->s_dist.y = (game->pos.y - game->map.y + 1) * game->d_dist.y;
	}
}

static void	dda(t_params *data, int x)
{
	int	hit = 0;
	t_game	game;
	int		perp_wall_dist;
	int		side = 0;

	game = data->game;

	while (hit == 0)
	{
		if (game.s_dist.x < game.s_dist.y)
		{
			game.s_dist.x += game.d_dist.x;
			game.map.x += game.step.x;
			side = 0;
		}
		else
		{
			game.s_dist.y += game.d_dist.y;
			game.map.y += game.step.y;
			side = 1;
		}
		if (data->map[(int)data->game.map.x][(int)data->game.map.y] == '1')
			hit = 1;
	}
	if (side == 0)
		perp_wall_dist = (game.s_dist.x - game.d_dist.x);
	else
		perp_wall_dist = (game.s_dist.y - game.d_dist.y);
	int line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	int draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if(draw_start < 0) draw_start = 0;
	int draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if(draw_end >= WINDOW_HEIGHT) draw_end = WINDOW_HEIGHT - 1;
	my_mlx_pixel_put(data->image, x, draw_start, data->config->f_color);
	my_mlx_pixel_put(data->image, x, draw_end, data->config->f_color);
}

static void	draw_frame(t_params *data)
{
	int		x;
	t_point	ray_dir;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray_dir = calc_ray(&(data->game), x);
		calc_delta_distance(&(data->game), ray_dir);
		calc_side_distance(&(data->game), ray_dir);
		dda(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.ptr, 0, 0);
}

int	game_loop(t_params *data)
{
	if (data->game.won)
		clean_exit(data, EXIT_SUCCESS);
	if (data->game.lost)
		clean_exit(data, EXIT_FAILURE);
	if (data->game.player_moved)
	{
		data->game.player_moved = 0;
		draw_frame(data);
	}
	return (0);
}
