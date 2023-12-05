#include "cub3d.h"

void	*setup_variables(t_params *data)
{
	t_point	start;

	start = find_spawnpoint(data->map);
	data->game.pos.x = start.x + 0.5;
	data->game.pos.y = start.y + 0.5;
	data->game.dir.x = -1;
	data->game.dir.y = 0;
	data->game.plane.x = 0;
	data->game.plane.y = 0.66;
	data->game.player_moved = 1;
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
