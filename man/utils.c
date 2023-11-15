#include "../incl/cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	int	alpha;
	int	argb;

	alpha = 0xFF;
	argb = (alpha << 24) | (r << 16) | (g << 8) | b;
	return ((unsigned int)argb);
}

void	error_msg(char *error, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Cub3D: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

void	print_tab(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("Arr[%i]: |%s|\n", i, arr[i]);
}
