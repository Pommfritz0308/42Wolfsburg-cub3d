#include "../incl/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	data;

	if (argc != 2)
	{
		write (1, "\x1b[31mWRONG NUMBER OF ARGUMENTS\n\x1b[0m", 36);
		return (1);
	}
	printf("arg: %s\n", argv[1]);
	create_window(&data);
	// init_map_data();
}
