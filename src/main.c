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
	// create_window(&data);
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
	if (check_colors(error))
		clean_exit(data, EXIT_FAILURE);
	check_map(data);
	// if (check_map())
	// 	return (1);
	return (0);
}
