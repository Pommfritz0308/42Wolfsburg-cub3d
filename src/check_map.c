#include "cub3d.h"

static int	valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01NSEW ", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	has_spawnpoint(char **map)
{
	int	i;
	int	j;
	int	spawnpoint;

	i = 0;
	spawnpoint = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (spawnpoint == 1)
					return (0);
				spawnpoint = 1;
			}
			j++;
		}
		i++;
	}
	return (spawnpoint);
}

static t_point	find_spawnpoint(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				return ((t_point){i, j});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

static int	is_enclosed(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y] == 0)
		return (0);
	if (map[x][y] == -1 || map[x][y] == '1')
		return (1);
	map[x][y] = -1;
	return (is_enclosed(map, x - 1, y) && is_enclosed(map, x, y - 1)
		&& is_enclosed(map, x + 1, y) && is_enclosed(map, x, y + 1));
}

// int data[][6] = {
// {'1', '1', '1', '1', '1', 0},
// {'1', 'E', '0', '1', '1', 0},
// {'1', '0', '1', '1', '1', 0},
// {'1', '0', '0', '0', '1', 0},
// {'1', '1', '1', '1', '1', 0},
// {0, 0, 0, 0, 0, 0},
// };

// int	*doubleIntPtr[] = {data[0], data[1], data[2], data[3], data[4], data[5], NULL};

int	check_map(t_params *params)
{
	t_point	spawnpoint;

	if (!valid_characters(params->map))
	{
		printf("Error\nCub3D: invalid characters in map\n");
		return (0);
	}
	if (!has_spawnpoint(params->map))
	{
		printf("Error\nCub3D: wrong amount of spawnpoints\n");
		return (0);
	}
	spawnpoint = find_spawnpoint(params->map);
	printf("Spawnpoint: %d, %d\n", spawnpoint.x, spawnpoint.y);
	if (!is_enclosed(params->map, spawnpoint.x, spawnpoint.y))
	{
		printf("Error\nCub3D: map is not enclosed\n");
		return (0);
	}
	put_color_msg("\x1b[32m", "Map √");
	return (1);
}
