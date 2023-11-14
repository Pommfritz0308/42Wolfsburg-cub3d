#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

struct	s_config;

typedef struct s_params {
	void			*win;
	void			*mlx;
	int				map_fd;
	struct s_config	*config;
}	t_params;

typedef struct s_config {
	unsigned int	f_color;
	unsigned int	c_color;
	char			*textures[4];
}	t_config;

unsigned int		rgb_to_hex(int r, int g, int b);
int					handle_key_press(int keycode, t_params *data);
int					close_window(t_params *data);
bool				create_window(t_params *data);
void				open_map(t_params *data, char *file);
void				read_configuration(t_params *data);

#endif
