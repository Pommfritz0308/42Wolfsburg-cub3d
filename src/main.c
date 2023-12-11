#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_params	data;

	ft_bzero(&data, sizeof(t_params));
	if (argc != 2)
	{
		write (1, "\x1b[31mWRONG NUMBER OF ARGUMENTS\n\x1b[0m", 36);
		return (1);
	}
	if (parse_cub(&data, argv))
		return (1);
	data.mlx = mlx_init();
	setup_variables(&data);
	create_window(&data);
	clean_exit(&data, EXIT_FAILURE);
}

int	parse_cub(t_params *data, char **argv)
{
	const int	error[] = {0, 0};

	open_map(data, argv[1]);
	read_configuration(data);
	if (check_found(data))
		clean_exit(data, EXIT_FAILURE);
	data->config->f_color = handle_rgb(data->config->xpm[4], (int *)error);
	data->config->c_color = handle_rgb(data->config->xpm[5], (int *)error + 1);
	put_color_msg("\x1b[32m", "Configuration √");
	if (check_colors(error))
		clean_exit(data, EXIT_FAILURE);
	read_map(data);
	if (!data->map)
	{
		printf("Error\nCub3D: map not found\n");
		clean_exit(data, 1);
	}
	data->map = copy_and_equalize(data, data->map, ' ');
	if (!check_map(data))
		clean_exit(data, 1);
	return (0);
}
