#include "cub3d.h"

// int	parse_map(t_params *data)
// {

// }

char	**read_map(t_params *data)
{
	char	**map;
	char	*l;
	char	*temp;
	int		start;

	start = 0;
	l = gnl_w_counter(data, data->map_fd);
	temp = l;
	check_nline(temp, l, &start, data);
	while (l && l[0] != '\n')
	{
		l = gnl_w_counter(data, data->map_fd);
		if (l)
			temp = ft_strjoin(temp, l);
	}
	check_nline(temp, l, &start, data);
	map = ft_split(temp, '\n');
	print_tab(map);
	close(data->map_fd);
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

void	check_nline(char *temp, char *l, int *start, t_params *data)
{
	while (l)
	{
		if (l)
			free(l);
		if (l[0] != '\n')
		{
			if (*start)
			{
				if (l)
					free(l);
				free(temp);
				clean_exit(data, EXIT_FAILURE);
			}
			else
			{
				*start = 1;
				return ;
			}
		}
		l = gnl_w_counter(data, data->map_fd);
	}
}
