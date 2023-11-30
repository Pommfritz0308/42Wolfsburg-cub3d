#include "cub3d.h"

// int	parse_map(t_params *data)
// {

// }

char	**read_map(t_params *data)
{
	char	**map;
	char	*l;
	char	*temp;
	char	*new;
	int		start;

	start = 0;
	l = skip_nline(l, data);
	while (l && l[0] != '\n')
	{
		
	}
	map = ft_split(new, '\n');
	print_tab(map);
	check_nline(l, &start, data);
	close(data->map_fd);
	return (NULL);
}


char	*skip_nline(char *l, t_params *data)
{
	char	*l;

	l = gnl_w_counter(data->config->map_fd);
	while (l && l[0] == '\n')
	{
		free(l)
		l = gnl_w_counter(data->config->map_fd);
		if (l && l[0] != '\n')
			return (l);
	}
	return (NULL);
}

// int	*convert_char_to_int(char *str)
// {
// 	int	*arr;
// 	int	i;

// 	i = -1;
// 	if (!str)
// 		return (NULL);
// 	arr = ft_calloc(ft_strlen(str) + 1, sizeof(int));
// 	while (str[++i])
// 		arr[i] = str[i] - '0';
// 	free(str);
// 	return (arr);
// }
