#include "../incl/cub3d.h"

void	open_map(t_params *data, char *file)
{
	int		fd;
	char	*path;

	path = ft_strjoin("/Users/fbohling/Desktop/cub3d/maps/", file);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Cub3D");
		free(path);
		exit (0);
	}
	free(path);
	data->map_fd = fd;
}

void	read_configuration(t_params *data)
{
	const char	*identifier[] = {"NO", "SO", "EA", "WE", "F", "C", NULL};
	int			i;
	char		*l;

	data->config = malloc(sizeof(t_config));
	data->config->found = ft_calloc(6, sizeof(int));
	data->config->xpm = ft_calloc(7, sizeof(char *));
	l = get_next_line(data->map_fd);
	while (l)
	{
		i = 0;
		while (identifier[i])
		{
			identifier_value(data, (char *)identifier[i], l, i);
			i++;
		}
		free(l);
		l = get_next_line(data->map_fd);
	}
}

void	identifier_value(t_params *data, char *identifier, char *l, int i)
{
	if (l[0] && l[0] != '\n')
	{
		data->config->p = identifier_value_pos(l, (char *)identifier);
		if (data->config->p > -1 && data->config->found[i] == 0)
		{
			data->config->xpm[i] = ft_substr(l + data->config->p,
					0, ft_strlen(l) - data->config->p - 1);
			data->config->found[i] = 1;
		}
	}
}

int	identifier_value_pos(char *str, char *search)
{
	int	i;
	int	j;

	i = 0;
	if (!search || !search[0] || !str)
		return (-1);
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		j = 0;
		while (str[i] == search[j] && str[i] && search[j])
		{
			i++;
			j++;
		}
		if (search[j] == '\0')
		{
			while (str[i] == ' ')
				i++;
			return (i);
		}
		else
			break ;
	}
	return (-1);
}

int	check_found(t_params *data)
{
	int	i;
	int	ret;

	ret = 0;
	i = 5;
	while (i > 0)
	{
		if (data->config->found[i] == 0)
			ret = 1;
		i--;
	}
	if (ret == 1)
	{
		while (i < 6)
		{
			if (data->config->found[i] == 1)
				free(data->config->xpm[i]);
			i++;
		}
		free(data->config->xpm);
	}
	free(data->config->found);
	return (ret);
}
