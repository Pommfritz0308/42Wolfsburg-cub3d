#include "../incl/cub3d.h"

int	main(int argc, char **argv)
{
	t_params	data;

	if (argc != 2)
	{
		write (1, "\x1b[31mWRONG NUMBER OF ARGUMENTS\n\x1b[0m", 36);
		return (1);
	}
	if (parse_cub(&data, argv))
		return (1);
	create_window(&data);
	ft_free_array(data.config->xpm);
	free(data.config);
	// init_map_data();
}

int	parse_cub(t_params *data, char **argv)
{
	const int	error[] = {0, 0};

	open_map(data, argv[1]);
	read_configuration(data);
	if (check_found(data))
		return (free(data->config), 1);
	data->config->f_color = handle_rgb(data->config->xpm[4], (int *)error);
	data->config->c_color = handle_rgb(data->config->xpm[5], (int *)error + 1);
	if (error[0] || error[1])
	{
		printf("Error\n");
		if (error[0])
			printf("Cub3D: \"F\": invalid configuration (expected: R,G,B)\n");
		if (error[1])
			printf("Cub3D: \"C\": invalid configuration (expected: R,G,B)\n");
		ft_free_array(data->config->xpm);
		return (free(data->config), 1);
	}
	return (0);
}
