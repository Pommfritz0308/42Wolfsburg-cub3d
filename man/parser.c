#include "../incl/cub3d.h"

int	open_map(char *file)
{
	int		fd;
	char	*path;

	path = ft_strjoin("/Users/fbohling/Desktop/cub3d/maps/", file);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Cub3D: ");
		exit (0);
	}
}
