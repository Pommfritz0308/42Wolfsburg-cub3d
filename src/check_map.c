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

t_point	find_spawnpoint(char **map)
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
				return ((t_point){i + 0.5, j + 0.5});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

static int	is_enclosed(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[x] == NULL || map[x][y] == 0)
		return (0);
	if (map[x][y] == -1 || map[x][y] == '1')
		return (1);
	map[x][y] = -1;
	return (is_enclosed(map, x - 1, y) && is_enclosed(map, x, y - 1)
		&& is_enclosed(map, x + 1, y) && is_enclosed(map, x, y + 1));
}

static void	restore_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == -1)
				map[x][y] = '0';
			y++;
		}
		x++;
	}
}

int	check_map(t_params *params)
{
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
	params->game.pos = find_spawnpoint(params->map);
	params->game.direction
		= params->map[(int)params->game.pos.x][(int)params->game.pos.y];
	if (!is_enclosed(params->map, params->game.pos.x, params->game.pos.y))
	{
		printf("Error\nCub3D: map is not enclosed\n");
		return (0);
	}
	put_color_msg("\x1b[32m", "Map √");
	restore_map(params->map);
	return (1);
}
