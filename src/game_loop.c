#include "cub3d.h"

static void	draw_frame(t_params *data)
{
	int		x;
	t_point	ray_dir;

	ray_dir = 0;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		calc_vector(data, x, ray_dir);
		x++;
	}
}

static void	calc_vector(t_params *data, int x, t_point ray_dir)
{
	data->game->cam->x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray_dir.x = data->game->dir->x
		+ data->game->plane->x * data->game->cam->x;
	ray_dir.y = data->game->dir->y
		+ data->game->plane->y * data->game->cam->y;
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
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
	return (0);
}
