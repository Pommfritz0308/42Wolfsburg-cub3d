#include "../incl/cub3d.h"

int	open_textures(t_params *data)
{
	int	fd;
	int	i;

	i = 0;
	data->texture_fds = ft_calloc(4, sizeof(int));
	data->texture_fds[i] = open(data->config->xpm[i], O_RDONLY);
	i++;
	while (data->texture_fds[i] < 0 && i <= 4)
	{
		data->texture_fds[i] = open(data->config->xpm[i], O_RDONLY);
		i++;
	}
	if (i != 5)
	{
		while (i > 0)
		{
			close(data->texture_fds[i]);
			i--;
		}
	}
}

int	open_file(t_params *data)
{
	int	fd;

	fd = open(data->config->xpm[0], O_RDONLY);
	if (fd < 0)
	{

	}
}
