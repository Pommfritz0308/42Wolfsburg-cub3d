#include "cub3d.h"

static void	draw_circle(t_params *data, int x, int y, int color)
{
	t_game	*g;

	g = &data->game;
	my_mlx_pixel_put(data->image, data->xc + x, data->yc + y, color);
	my_mlx_pixel_put(data->image, data->xc - x, data->yc + y, color);
	my_mlx_pixel_put(data->image, data->xc + x, data->yc - y, color);
	my_mlx_pixel_put(data->image, data->xc - x, data->yc - y, color);
	my_mlx_pixel_put(data->image, data->xc + y, data->yc + x, color);
	my_mlx_pixel_put(data->image, data->xc - y, data->yc + x, color);
	my_mlx_pixel_put(data->image, data->xc + y, data->yc - x, color);
	my_mlx_pixel_put(data->image, data->xc - y, data->yc - x, color);
}

static void	draw_player(t_params *data, double pos_x, double pos_y, int color)
{
	int		x;
	int		y;
	int		d;
	t_game	*g;

	g = &data->game;
	data->xc = g->box_size * pos_x;
	data->yc = g->box_size * pos_y;
    d = 3 - 2 * data->radius;
	x = 0;
	y = data->radius;
	draw_circle(data, x, y, color);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle(data, x, y, color);
	}
}

static void	draw_outline(t_params *data, int x, int y, int color)
{
	int		i;
	t_game	*g;

	g = &data->game;
	i = 0;
	while (i <= g->box_size)
	{
		my_mlx_pixel_put(data->image, x * g->box_size
			+ i, (y + 1) * g->box_size, color);
		my_mlx_pixel_put(data->image, (x + 1) * g->box_size,
			y * g->box_size + i, color);
		i++;
	}
}

static void	fill_box(t_params *data, int x, int y, int color)
{
	int		i;
	int		j;
	t_game	*g;

	g = &data->game;
	i = 0;
	while (i++ < g->box_size - 1)
	{
		j = 0;
		while (j++ < g->box_size - 1)
		{
			my_mlx_pixel_put(data->image, x * g->box_size
				+ i, y * g->box_size + j, color);
		}
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
			draw_outline(data, x, y, 0xFF000000);
			if (data->map[y][x] == '1')
				fill_box(data, x, y, 0x5E6137);
			else if (data->map[y][x] == '0')
				fill_box(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	draw_player(data, g->pos.y, g->pos.x, 0x00FF0000);
}
