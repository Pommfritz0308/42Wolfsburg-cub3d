#include "../incl/cub3d.h"

// int	open_textures(t_params *data)
// {
	// int	i;

	// i = 0;
	// data->texture_fds = ft_calloc(4, sizeof(int));
	// data->texture_fds[i] = open(data->config->xpm[i], O_RDONLY);
	// if (data->texture_fds[i] < 0)
	// 	perror(data->config->xpm[i]);
	// i++;
	// while (data->texture_fds[i] < 0 && i <= 4)
	// {
	// 	data->texture_fds[i] = open(data->config->xpm[i], O_RDONLY);
	// 	if (data->texture_fds[i] < 0)
	// 		perror(data->config->xpm[i]);
	// 	i++;
	// }
	// if (i != 5)
	// {
	// 	while (i < 0)
	// 	{
	// 		close(data->texture_fds[i]);
	// 		i--;
	// 	}
	// 	return (1);
	// }
	// return (0);
// }

int	handle_rgb(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!str[0])
		return (-1);
	while (str[i] && flag < 3)
	{
		while ((str[i]) == ' ')
			i++;
		if (ft_isdigit(str[i]) == 1)
		{

		}
		else if (str[i] == ',')
		{

		}
	}
}
