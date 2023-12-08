#include "cub3d.h"

void	find_hit(t_params *data, double perp_wall_dist, t_point ray_dir)
{
	t_game	*g;

	g = &data->game;
	if (g->side == 0)
		g->wall_x = g->pos.y + perp_wall_dist * ray_dir.y;
	else
		g->wall_x = g->pos.x + perp_wall_dist * ray_dir.x;
	g->wall_x -= floor(g->wall_x);

}

void	fill_texture_buffer(t_params *data, int x)
{
	double		step;
	double		tex_pos;
	u_int32_t	color;
	int			y;

	data->game.tex.x = (int)(data->game.wall_x * (double)data->textures[0].width);
	step = 1.0 * data->textures[0].height / data->game.line_height;
	tex_pos = (data->game.draw_start - WINDOW_HEIGHT
			/ 2 + data->game.line_height / 2) * step;
	y = data->game.draw_start;
	while (y < data->game.draw_end)
	{
		data->game.tex.y = (int)tex_pos & (data->textures[0].height - 1);
		tex_pos += step;
		color = my_mlx_get_pixel_color(data->textures[0],
				data->game.tex.x, data->game.tex.y);
		my_mlx_pixel_put(data->image, x, y, color);
		y++;
	}
}

