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

void	*setup_variables(t_params *data)
{
	printf("pos x: %f, pos y: %f\n", data->game.pos.x, data->game.pos.y);
	data->game.plane.x = 0;
	data->game.plane.y = 0.66;
	data->game.player_moved = 1;
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
