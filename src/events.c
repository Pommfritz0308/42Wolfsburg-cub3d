#include "cub3d.h"

// int	handle_mouse_events()
// {
// 	retrun (0);
// }

int	handle_key_event(int keycode, t_params *data)
{
	printf("%i\n", keycode);
	data->game.cur_keycode = keycode;
	if (keycode == XK_Escape)
		close_window(data);
	else if (keycode == 65363 || keycode == 65361)
	{
		data->game.cur_keycode = keycode;
		data->game.is_rotating = true;
	}
	else if (keycode == 65363 + 256 || keycode == 65361 + 256)
	{
		data->game.cur_keycode = 0;
		data->game.is_rotating = false;
	}
	return (0);
}

int	turn_view(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->cur_keycode == 65363)
	{
		old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->rot_speed) - game->dir.y * sin(-game->rot_speed);
		game->dir.y = old_dir_x * sin(-game->rot_speed) + game->dir.y * cos(-game->rot_speed);
		old_plane_x = game->plane.x;
		game->plane.x = game->plane.x * cos(-game->rot_speed) - game->plane.y * sin(-game->rot_speed);
		game->plane.y = old_plane_x * sin(-game->rot_speed) + game->plane.y * cos(-game->rot_speed);
	}
	if (game->cur_keycode == 65361)
	{
		old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(game->rot_speed) - game->dir.y * sin(game->rot_speed);
		game->dir.y = old_dir_x * sin(game->rot_speed) + game->dir.y * cos(game->rot_speed);
		old_plane_x = game->plane.x;
		game->plane.x = game->plane.x * cos(game->rot_speed) - game->plane.y * sin(game->rot_speed);
		game->plane.y = old_plane_x * sin(game->rot_speed) + game->plane.y * cos(game->rot_speed);
	}
	return (0);
}
