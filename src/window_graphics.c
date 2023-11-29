#include "cub3d.h"

bool	create_window(t_params *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	mlx_string_put(data->mlx, data->win, 1000, 500, data->config->c_color, "TEST COLOR 1");
	mlx_string_put(data->mlx, data->win, 500, 500, data->config->f_color, "TEST COLOR 2");
	mlx_key_hook(data->win, &handle_key_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	return (true);
}

int	close_window(t_params *data)
{
	clean_exit(data, EXIT_SUCCESS);
	return (0);
}
