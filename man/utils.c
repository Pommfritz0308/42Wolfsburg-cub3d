#include "../incl/cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	int	alpha;
	int	argb;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
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

	i = 0;
	while (arr[i])
	{
		printf("Arr[%i]: |%s|\n", i, arr[i]);
		i++;
	}
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
