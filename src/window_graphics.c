#include "cub3d.h"

bool	create_window(t_params *data)
{
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	mlx_hook(data->win, 2, 0, &handle_key_event, data);
	mlx_hook(data->win, 3, 0, &handle_key_event, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (true);
}

int	close_window(t_params *data)
{
	clean_exit(data, EXIT_SUCCESS);
	return (0);
}
