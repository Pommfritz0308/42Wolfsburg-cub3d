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

static void	dda_helper(t_game game, int x, t_params *data, int side)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;

	if (side == 0)
		perp_wall_dist = (game.s_dist.x - game.d_dist.x);
	else
		perp_wall_dist = (game.s_dist.y - game.d_dist.y);
	printf("perp wall dist: %f\n", perp_wall_dist);
	line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	y = 0;
	// printf("line height: %i\n", line_height);
	while (y++ < draw_start)
		my_mlx_pixel_put(data->image, x, y, data->config->c_color);
	y = draw_end;
	while (y++ < WINDOW_HEIGHT)
		my_mlx_pixel_put(data->image, x, y, data->config->f_color);
}

static void	dda(t_params *data, int x)
{
	t_game	game;

	game = data->game;
	game.side = 0;
	game.hit = 0;
	while (game.hit == 0)
	{
		if (game.s_dist.x < game.s_dist.y)
		{
			game.s_dist.x += game.d_dist.x;
			game.map.x += game.step.x;
			game.side = 0;
		}
		else
		{
			game.s_dist.y += game.d_dist.y;
			game.map.y += game.step.y;
			game.side = 1;
		}
		if (data->map[(int)game.map.x][(int)game.map.y] == '1')
			break ;
	}
	dda_helper(game, x, data, game.side);
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

void	clear_image(t_params *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data->image, j, i, 0xFF000000);
			j++;
		}
		i++;
	}
}

int	game_loop(t_params *data)
{
	if (data->game.won)
		clean_exit(data, EXIT_SUCCESS);
	if (data->game.lost)
		clean_exit(data, EXIT_FAILURE);
	clear_image(data);
	draw_frame(data);
	return (0);
}
