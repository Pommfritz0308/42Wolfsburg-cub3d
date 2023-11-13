#include "../incl/cub3d.h"

// int	handle_mouse_events()
// {
// 	retrun (0);
// }

int	handle_key_press(int keycode, t_vars *data)
{
	printf("Keycode: %i\n", keycode);
	if (keycode == 53)
		close_window(data);
	return (0);
}
