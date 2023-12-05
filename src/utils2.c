#include "cub3d.h"

void	put_color_msg(char *color, char *str)
{
	write(1, color, ft_strlen(color));
	ft_putendl_fd(str, 2);
	write(1, "\x1b[0m", 5);
}

void	my_mlx_pixel_put(t_image image, int x, int y, int color)
{
	char	*dst;

	dst = image.buffer + (y * image.line_bytes + x
			* (image.pixel_bits / 8));
	*(unsigned int *)dst = color;
}

