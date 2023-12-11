#include "cub3d.h"

static void	free_mlx(t_params *params)
{
	if (params->win)
		mlx_destroy_window(params->mlx, params->win);
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
