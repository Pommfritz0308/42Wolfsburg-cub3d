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
	char		*line;
	t_config	config;

	data->config = &config;
	data->config->textures = ft_calloc(5, sizeof(char *));
	line = get_next_line(data->map_fd);
	while (line)
	{
		if (line[0] && line[0] != '\n')
		{
			printf("%i\n", ft_strstr(line, "NO"));
		}
		free(line);
		line = get_next_line(data->map_fd);
	}
	free(line);
}

int	ft_strstr(char *str, char *search)
{
	int	i;
	int	start;
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
		start = i;
		while (str[i] == search[j] && str[i] && search[j])
		{
			i++;
			j++;
		}
		if (search[j] == '\0')
			return (start);
		else
			break ;
	}
	return (-1);
}
