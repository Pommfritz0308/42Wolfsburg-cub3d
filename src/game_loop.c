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
		game->dist.x = INFINITY;
	else
		game->dist.x = fabs(1 / ray_dir.x);
	if (!ray_dir.y)
		game->dist.y = INFINITY;
	else
		game->dist.y = fabs(1 / ray_dir.y);
}

// static void	calc_side_distance(t_game *game)
// {
// 	if (game->ray_dir.x < 0)
// 	{
// 		game->step.x = -1;
// 		sideDistX = (posX - mapX) * deltaDistX;
// 	}
// 	else
// 	{
// 		game->step.x = 1;
// 		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 	}
// 	if (game->ray_dir.y < 0)
// 	{
// 		game->step.y -1;
// 		sideDistY = (posY - mapY) * deltaDistY;
// 	}
// 	else
// 	{
// 		game->step.y = 1;
// 		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 	}
// }

static void	draw_frame(t_game *game)
{
	int		x;
	t_point	ray_dir;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ray_dir = calc_ray(game, x);
		calc_delta_distance(game, ray_dir);
		x++;
	}
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
		draw_frame(&(data->game));
		// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}
