#include "cub3d.h"

void	printf_map(t_params *data)
{
	int	i = 0;
	int j = 0;

	while (data->map[i])
	{
		while (data->map[i][j])
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

static t_point	set_direction_vector(char direction)
{
	t_point	dir;

	if (direction == 'N')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else if (direction == 'S')
	{
		dir.x = 1;
		dir.y = 0;
	}
	else if (direction == 'W')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else
	{
		dir.x = 0;
		dir.y = 1;
	}
	return (dir);
}

void	load_textures(t_params *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		data->textures[i].ptr = NULL;
		printf("xpm: %s\n", data->config->xpm[i]);
		data->textures[i].ptr = mlx_xpm_file_to_image(data->mlx,
				data->config->xpm[i], &data->textures[i].width,
				&data->textures[i].height);
		if (!data->textures[i].ptr)
			clean_exit(data, EXIT_FAILURE);
		data->textures[i].buffer = mlx_get_data_addr(data->textures[i].ptr,
				&data->textures[i].pixel_bits, &data->textures[i].line_bytes,
				&data->textures[i].endian);
		printf("buffer ptr: %p\n", data->textures[i].buffer);
		i++;
	}
}

void	*setup_variables(t_params *data)
{
	printf("pos x: %f, pos y: %f\n", data->game.pos.x, data->game.pos.y);
	data->game.plane.x = 0;
	data->game.plane.y = 0.66;
	load_textures(data);
	data->game.dir = set_direction_vector(data->game.direction);
	printf("mlx ptr: %p\n", data->mlx);
	data->image.ptr = mlx_new_image(
			data->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->image.buffer = mlx_get_data_addr(
			data->image.ptr,
			&data->image.pixel_bits,
			&data->image.line_bytes,
			&data->image.endian);
	return (NULL);
}

