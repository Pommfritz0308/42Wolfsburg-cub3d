#include "../incl/cub3d.h"

bool	create_window(t_params *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3D");
	mlx_key_hook(data->win, &handle_key_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	return (true);
}

int	close_window(t_params *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
