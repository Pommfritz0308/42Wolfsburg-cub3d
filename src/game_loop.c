#include "cub3d.h"

static void	draw_crosshair(t_params *data)
{
	int	x;
	int	y;

	x = WINDOW_WIDTH / 2 - 10;
	while (x < WINDOW_WIDTH / 2 + 10)
	{
		y = WINDOW_HEIGHT / 2 - 1;
		while (y < WINDOW_HEIGHT / 2 + 1)
		{
			my_mlx_pixel_put(data->image, x, y, CROSSHAIR_COLOR);
			y++;
		}
		x++;
	}
	y = WINDOW_HEIGHT / 2 - 10;
	while (y < WINDOW_HEIGHT / 2 + 10)
	{
		x = WINDOW_WIDTH / 2 - 1;
		while (x < WINDOW_WIDTH / 2 + 1)
		{
			my_mlx_pixel_put(data->image, x, y, CROSSHAIR_COLOR);
			x++;
		}
		y++;
	}
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
		dda(data, x, ray_dir);
		x++;
	}
	draw_minimap(data);
	draw_crosshair(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.ptr, 0, 0);
}

int	game_loop(t_params *data)
{
	if (data->game.won)
		clean_exit(data, EXIT_SUCCESS);
	if (data->game.lost)
		clean_exit(data, EXIT_FAILURE);
	if (data->game.player_moved)
		draw_frame(data);
	data->game.player_moved = 0;
	return (0);
}
