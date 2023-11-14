#include "../incl/cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	int	alpha;
	int	argb;

	alpha = 0xFF;
	argb = (alpha << 24) | (r << 16) | (g << 8) | b;
	return ((unsigned int)argb);
}
