#include "cub3d.h"

static int	valid_characters(int **map)
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

static int	has_spawnpoint(int **map)
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

static t_point	find_spawnpoint(int **map)
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

static int	is_enclosed(int **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x][y] == '0')
		return (0);
	if (map[x][y] == -1 || map[x][y] == '1')
		return (1);
	map[x][y] = -1;
	return (is_enclosed(map, x - 1, y) && is_enclosed(map, x, y - 1)
		&& is_enclosed(map, x + 1, y) && is_enclosed(map, x, y + 1));
}

int data[][4] = {
	{'1', '1', '1', 0},
	{'1', 'W', '1', 0},
	{'1', '0', '1', 0},
	{0, 0, 0, 0},
};

int *doubleIntPtr[] = {data[0], data[1], data[2], data[3], NULL};

int	check_map(t_params *params)
{
	t_point	spawnpoint;

	(void)params;
	if (!valid_characters(doubleIntPtr))
	{
		printf("Invalid characters in map\n");
		return (0);
	}
	if (!has_spawnpoint(doubleIntPtr))
	{
		printf("Wrong amount of spawnpoints\n");
		return (0);
	}
	spawnpoint = find_spawnpoint(doubleIntPtr);
	printf("Spawnpoint: %d, %d\n", spawnpoint.x, spawnpoint.y);
	if (!is_enclosed(doubleIntPtr, spawnpoint.x, spawnpoint.y))
	{
		printf("Map is not enclosed\n");
		return (0);
	}
	printf("Map is valid\n");
	return (1);
}
