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
	char	*line;

	line = get_next_line(data->map_fd);
	while (line)
	{
		if (line[0] && line[0] != '\n')
			isolate_params(line);
		free(line);
		line = get_next_line(data->map_fd);
	}
	free(line);
}

