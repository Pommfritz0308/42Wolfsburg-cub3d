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

static int	get_tex_num(int side, t_point direction)
{
	if (side == 0 && direction.x > 0)
		return (1);
	else if (side == 1 && direction.y < 0)
		return (3);
	else if (side == 0 && direction.x < 0)
		return (0);
	else
		return (2);
}

void	fill_texture_buffer(t_params *data, int x, t_point ray_dir)
{
	double		step;
	double		tex_pos;
	u_int32_t	color;
	int			y;
	int			tex_num;

	tex_num = get_tex_num(data->game.side, ray_dir);
	data->game.tex.x = (int)(data->game.wall_x * (double)data->textures[tex_num].width);
	if (data->game.side == 0 && ray_dir.x > 0)
		data->game.tex.x = (double)data->textures[tex_num].width - data->game.tex.x - 1;
	if (data->game.side == 1 && ray_dir.y < 0)
		data->game.tex.x = (double)data->textures[tex_num].width - data->game.tex.x - 1;
	step = 1.0 * data->textures[tex_num].height / data->game.line_height;
	tex_pos = (data->game.draw_start - WINDOW_HEIGHT
			/ 2 + data->game.line_height / 2) * step;
	y = data->game.draw_start;
	while (y++ < data->game.draw_end)
	{
		data->game.tex.y = (int)tex_pos & (data->textures[tex_num].height - 1);
		tex_pos += step;
		color = my_mlx_get_pixel_color(data->textures[tex_num],
				data->game.tex.x, data->game.tex.y);
		my_mlx_pixel_put(data->image, x, y, color);
	}
}

