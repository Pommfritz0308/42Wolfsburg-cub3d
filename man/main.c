#include "../incl/cub3d.h"

int	main(int argc, char **argv)
{
	t_params	data;

	if (argc != 2)
	{
		write (1, "\x1b[31mWRONG NUMBER OF ARGUMENTS\n\x1b[0m", 36);
		return (1);
	}
	open_map(&data, argv[1]);
	read_configuration(&data);
	if (check_found(&data))
		return (free(data.config), 1);
	print_tab(data.config->xpm);
	// open_textures(&data);
	// create_window(&data);
	ft_free_array(data.config->xpm);
	free(data.config);
	// init_map_data();
}
