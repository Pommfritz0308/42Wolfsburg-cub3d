#include "cub3d.h"

void	destroy_textures(t_params *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (data->textures[i].ptr)
			mlx_destroy_image(data->mlx, data->textures[i].ptr);
		data->textures[i].ptr = NULL;
		i++;
	}
}

static void	free_mlx(t_params *params)
{
	destroy_textures(params);
	if (params->win)
		mlx_destroy_window(params->mlx, params->win);
	if (params->image.ptr)
		mlx_destroy_image(params->mlx, params->image.ptr);
	if (params->mlx)
		mlx_destroy_display(params->mlx);
	free(params->mlx);
}

void	clean_exit(t_params *params, int exit_code)
{
	free_mlx(params);
	if (params->config->found)
		free(params->config->found);
	if (params->config->xpm)
		ft_free_array(params->config->xpm);
	if (params->map)
		ft_free_array(params->map);
	if (params->config)
		free(params->config);
	exit(exit_code);
}
