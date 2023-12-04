#include "cub3d.h"

void	put_color_msg(char *color, char *str)
{
	write(1, color, ft_strlen(color));
	ft_putendl_fd(str, 2);
	write(1, "\x1b[0m", 5);
}
