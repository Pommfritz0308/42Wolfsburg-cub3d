#include "cub3d.h"

// int	parse_map(t_params *data)
// {

// }

char	**read_map(t_params *data)
{
	char	*l;
	char	*new;
	int		start;
	char	*temp;

	start = 0;
	new = NULL;
	l = skip_nline(data);
	while (l && l[0] != '\n')
	{
		if (new == NULL)
		{
			new = ft_strdup(l);
			free(l);
		}
		else
		{
			temp = ft_strjoin(new, "\n");
			free(new);
			new = ft_strjoin(temp, l);
			free(l);
			free(temp);
		}
		l = gnl_w_counter(data, data->map_fd);
	}
	check_nline(data, l, new);
	data->map = ft_split(new, '\n');
	free(new);
	print_tab(data->map);
	close(data->map_fd);
	return (NULL);
}


char	*skip_nline(t_params *data)
{
	char	*l;

	l = gnl_w_counter(data, data->map_fd);
	while (l && l[0] == '\n')
	{
		free(l);
		l = gnl_w_counter(data, data->map_fd);
		if (l && l[0] != '\n')
			return (l);
	}
	return (NULL);
}

void	check_nline(t_params *data, char *l, char *str)
{
	while (l)
	{
		if (l[0] != '\n')
		{
			free(l);
			free(str);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Cub3D: new line in map detected", 2);
			clean_exit(data, 1);
		}
		free(l);
		l = gnl_w_counter(data, data->map_fd);
	}
	return ;
}

// char	**copy_and_equalize(char **arr, char c)
// {

// }

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
