#include "cub3d.h"

static void	draw_frame(t_params *data)
{
	int	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		
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
		draw_frame(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	}
	return (0);
}
