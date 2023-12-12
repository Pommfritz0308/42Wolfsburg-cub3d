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
		data->textures[i].ptr = mlx_xpm_file_to_image(data->mlx,
				data->config->xpm[i], &data->textures[i].width,
				&data->textures[i].height);
		if (!data->textures[i].ptr)
			clean_exit(data, EXIT_FAILURE);
		data->textures[i].buffer = mlx_get_data_addr(data->textures[i].ptr,
				&data->textures[i].pixel_bits, &data->textures[i].line_bytes,
				&data->textures[i].endian);
		i++;
	}
}

void	*setup_variables(t_params *data)
{
	data->game.plane.x = 0;
	data->game.plane.y = 0.66;
	load_textures(data);
	data->game.dir = set_direction_vector(data->game.direction);
	data->image.ptr = mlx_new_image(
			data->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->image.buffer = mlx_get_data_addr(
			data->image.ptr,
			&data->image.pixel_bits,
			&data->image.line_bytes,
			&data->image.endian);
	data->game.box_size = WINDOW_HEIGHT / ft_tablen(data->map) / 6;
	data->game.player_moved = 1;
	data->xc = data->game.box_size / 2;
	data->yc = data->game.box_size / 2;
	data->radius = data->game.box_size / 4;
	return (NULL);
}
