#include "../incl/cub3d.h"

int	handle_rgb(char *str)
{
	int		i;
	int		hex_color;
	char	**arr;

	i = 0;
	if (!str[0] || handle_rgb_helper(str))
		return (-1);
	arr = ft_split(str, ',');
	while (arr[i])
		i++;
	if (i != 3)
		return (-1);
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = ft_strtrim(arr[i], " ");
	}
	hex_color = rgb_to_hex(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	return (hex_color);
}

int	handle_rgb_helper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}
