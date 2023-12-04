#include "cub3d.h"

// int	handle_mouse_events()
// {
// 	retrun (0);
// }

int	handle_key_press(int keycode, t_params *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	return (0);
}
