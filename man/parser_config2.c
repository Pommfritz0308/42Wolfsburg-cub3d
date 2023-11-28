#include "../incl/cub3d.h"

int	handle_rgb(char *str, int *error)
{
	int		i;
	char	**arr;

	i = 0;
	if (!str[0] || check_rgb_code(str))
	{
		*error = 1;
		return (0);
	}
	arr = ft_split(str, ',');
	while (arr[i])
		i++;
	if (i != 3)
	{
		*error = 1;
		return (0);
	}
	return (handle_rgb_helper(arr));
}

int	check_rgb_code(char *str)
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

int	handle_rgb_helper(char **arr)
{
	char	*temp;
	int		i;
	int		hex_code;

	i = -1;
	while (arr[++i])
	{
		temp = ft_strtrim(arr[i], " ");
		free(arr[i]);
		arr[i] = temp;
	}
	hex_code = rgb_to_hex(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	ft_free_array(arr);
	return (hex_code);
}
