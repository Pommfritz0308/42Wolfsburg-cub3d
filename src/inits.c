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
	return (NULL);
}
