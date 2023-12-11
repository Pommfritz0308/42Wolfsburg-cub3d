#include "cub3d.h"

static void	draw_box(t_params *data, int x, int y, int color)
{
	int		i;
	int		j;
	t_game	*g;

	g = &data->game;
	i = 0;
	while (i < g->box_size.x)
	{
		j = 0;
		while (j < g->box_size.y)
		{
			my_mlx_pixel_put(data->image, x * g->box_size.x + i,
				y * g->box_size.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_params *data)
{
	int		x;
	int		y;
	t_game	*g;

	g = &data->game;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_box(data, x, y, 0x000FFF);
			else if (data->map[y][x] == '0')
				draw_box(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
