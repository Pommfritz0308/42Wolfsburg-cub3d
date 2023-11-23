#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define INVALID_CONFIG "invalid configuration"
# define NO_FILE_DIR "No such file or directory"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

struct	s_config;

typedef struct s_params {
	void			*win;
	void			*mlx;
	int				map_fd;
	struct s_config	*config;
}	t_params;

typedef struct s_config {
	int				c_flag;
	int				*found;
	int				p;
	unsigned int	f_color;
	unsigned int	c_color;
	char			**xpm;
}	t_config;

void				identifier_value(t_params *data,
						char *identifier, char *l, int i);
unsigned int		rgb_to_hex(int r, int g, int b);
int					handle_key_press(int keycode, t_params *data);
int					close_window(t_params *data);
int					identifier_value_pos(char *str, char *search);
int					check_found(t_params *data);
int					open_textures(t_params *data);
bool				create_window(t_params *data);
void				read_configuration(t_params *data);
void				open_map(t_params *data, char *file);
void				error_msg(char *error, char *str);
void				print_tab(char **arr);
void				ft_free_array(char **arr);
#endif
