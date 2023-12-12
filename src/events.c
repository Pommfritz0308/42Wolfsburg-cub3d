#include "cub3d.h"

void	init_events(t_params *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_event, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, handle_mouse_move, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}

int	handle_key_event(int keycode, t_params *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	else if (keycode == XK_Left || keycode == XK_Right)
		turn_view(&data->game, keycode);
	else if (keycode == XK_a || keycode == XK_d)
		move_hor(data, keycode);
	else if (keycode == XK_w || keycode == XK_s)
		move_ver(data, keycode);
	return (0);
}


int	handle_mouse_move(int x, int y, t_params *data)
{
	int				x_direction;

	(void)y;
	(void)x;
	x_direction = WINDOW_WIDTH / 2 - x;
	if (x_direction > 0)
		turn_view(&data->game, XK_Left);
	else if (x_direction < 0)
		turn_view(&data->game, XK_Right);
	mlx_mouse_move(data->mlx, data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}

int	turn_view(t_game *g, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == XK_Right)
	{
		old_dir_x = g->dir.x;
		g->dir.x = g->dir.x * cos(-ROT_SPEED) - g->dir.y * sin(-ROT_SPEED);
		g->dir.y = old_dir_x * sin(-ROT_SPEED) + g->dir.y * cos(-ROT_SPEED);
		old_plane_x = g->plane.x;
		g->plane.x = g->plane.x * cos(-ROT_SPEED)
			- g->plane.y * sin(-ROT_SPEED);
		g->plane.y = old_plane_x * sin(-ROT_SPEED)
			+ g->plane.y * cos(-ROT_SPEED);
	}
	if (keycode == XK_Left)
	{
		old_dir_x = g->dir.x;
		g->dir.x = g->dir.x * cos(ROT_SPEED) - g->dir.y * sin(ROT_SPEED);
		g->dir.y = old_dir_x * sin(ROT_SPEED) + g->dir.y * cos(ROT_SPEED);
		old_plane_x = g->plane.x;
		g->plane.x = g->plane.x * cos(ROT_SPEED) - g->plane.y * sin(ROT_SPEED);
		g->plane.y = old_plane_x * sin(ROT_SPEED) + g->plane.y * cos(ROT_SPEED);
	}
	return (0);
}

int	move_ver(t_params *data, int keycode)
{
	t_game	*g;

	g = &data->game;
	if (keycode == XK_w)
	{
		if (data->map[(int)(g->pos.x + g->dir.x
				* MOVE_SPEED)][(int)(g->pos.y)] == '0')
			g->pos.x += g->dir.x *  MOVE_SPEED;
		if (data->map[(int)(g->pos.x)]
			[(int)(g->pos.y + g->dir.y * MOVE_SPEED)] == '0')
			g->pos.y += g->dir.y * MOVE_SPEED;
	}
	else if (keycode == XK_s)
	{
		if (data->map[(int)(g->pos.x - g->dir.x
				* MOVE_SPEED)][(int)(g->pos.y)] == '0')
			g->pos.x -= g->dir.x * MOVE_SPEED;
		if (data->map[(int)(g->pos.x)]
			[(int)(g->pos.y - g->dir.y * MOVE_SPEED)] == '0')
			g->pos.y -= g->dir.y * MOVE_SPEED;
	}
	return (0);
}

int	move_hor(t_params *data, int keycode)
{
	t_game	*g;

	g = &data->game;
	if (keycode == XK_a)
	{
		if (data->map[(int)(g->pos.x - g->dir.y
				* MOVE_SPEED)][(int)(g->pos.y)] == '0')
			g->pos.x -= g->dir.y * MOVE_SPEED;
		if (data->map[(int)(g->pos.x)]
			[(int)(g->pos.y + g->dir.x * MOVE_SPEED)] == '0')
			g->pos.y += g->dir.x * MOVE_SPEED;
	}
	else if (keycode == XK_d)
	{
		if (data->map[(int)(g->pos.x + g->dir.y
				* MOVE_SPEED)][(int)(g->pos.y)] == '0')
			g->pos.x += g->dir.y * MOVE_SPEED;
		if (data->map[(int)(g->pos.x)]
			[(int)(g->pos.y - g->dir.x * MOVE_SPEED)] == '0')
			g->pos.y -= g->dir.x * MOVE_SPEED;
	}
	return (0);
}
