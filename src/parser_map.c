#include "cub3d.h"

// int	parse_map(t_params *data)
// {

// }

char	**read_map(t_params *data)
{
	char	*l;
	char	*new;
	char	*temp;

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
	close(data->map_fd);
	return (free(new), NULL);
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
	int	n_line_found;

	n_line_found = 0;
	while (l)
	{
		if (l[0] != '\n')
		{
			free(str);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Cub3D: new line in map detected", 2);
			n_line_found = 1;
		}
		free(l);
		l = gnl_w_counter(data, data->map_fd);
	}
	if (n_line_found)
		clean_exit(data, 1);
	return ;
}

char	**copy_and_equalize(t_params *data, char **a, int c)
{
	int			i;
	size_t		max_l;
	char		**new;

	if (!a[0] || !a)
		clean_exit(data, 1);
	max_l = 0;
	i = -1;
	while (a[++i])
	{
		if (ft_strlen(a[i]) > max_l)
			max_l = ft_strlen(a[i]);
	}
	new = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (a[++i])
	{
		new[i] = ft_calloc(max_l + 1, sizeof(char));
		ft_strlcpy(new[i], a[i], max_l + 1);
		if (ft_strlen(a[i]) < max_l)
			ft_memset((void *)(new[i] + ft_strlen(a[i])),
				c, max_l - ft_strlen(a[i]));
	}
	ft_free_array(a);
	return (new);
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
