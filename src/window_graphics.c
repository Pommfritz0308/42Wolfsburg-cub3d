#include "cub3d.h"

bool	create_window(t_params *data)
{
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	init_events(data);
	mlx_loop(data->mlx);
	return (true);
}

int	close_window(t_params *data)
{
	clean_exit(data, EXIT_SUCCESS);
	return (0);
}
