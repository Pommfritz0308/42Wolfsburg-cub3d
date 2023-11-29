#include "cub3d.h"

int	check_colors(const int *error)
{
	if (error[0] || error[1])
	{
		printf("Error\n");
		if (error[0])
			printf("Cub3D: \"F\": invalid configuration (expected: R,G,B)\n");
		if (error[1])
			printf("Cub3D: \"C\": invalid configuration (expected: R,G,B)\n");
		return (1);
	}
	return (0);
}
