#include "../incl/cub3d.h"

// int	parse_map(t_params *data)
// {

// }

char	**read_map(t_params *data)
{
	char	**map;
	char	*l;

	l = gnl_w_counter(data, data->map_fd);
	while (l && )
	{
		if (l[0] && l[0] != '\n')
		{
			free(l);
			l = gnl_w_counter(data, data->map_fd);
			continue ;
		}
		map[i] = gnl_w_counter(data, data->map_fd);
	}
	close(data->map_fd);
	return (NULL);
}
