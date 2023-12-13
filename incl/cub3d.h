#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define NOT_SPECIFIED "not specified"
# define INVALID_CONFIG "invalid configuration"
# define NO_FILE_DIR "no such file or directory"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MINIMAP_SCALE 6
# define ROT_SPEED 0.0115
# define MOVE_SPEED 0.125
# define CROSSHAIR_COLOR 0x00FF00

struct	s_config;

typedef struct s_point
{
	double			x;
	double			y;
}	t_point;

typedef struct s_game
{
	t_point		pos;
	t_point		dir;
	t_point		plane;
	t_point		cam;
	t_point		map;
	t_point		d_dist;
	t_point		step;
	t_point		s_dist;
	t_point		tex;
	int			box_size;
	char		direction;
	double		wall_x;
	int			won;
	int			lost;
	int			side;
	int			hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			player_moved;
}	t_game;

typedef struct s_image
{
	void			*ptr;
	char			*buffer;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				width;
	int				height;
}	t_image;

typedef struct s_params
{
	void			*win;
	void			*mlx;
	int				map_fd;
	int				line_n;
	int				count;
	int				yc;
	int				xc;
	int				radius;
	char			**map;
	t_image			image;
	t_image			textures[4];
	t_game			game;
	struct s_config	*config;
}	t_params;

typedef struct s_config
{
	int				c_flag;
	int				*found;
	int				p;
	unsigned int	f_color;
	unsigned int	c_color;
	char			**xpm;
}	t_config;

int					handle_mouse_move(int x, int y, t_params *data);
void				my_mlx_pixel_put(t_image image, int x, int y, int color);
void				*setup_variables(t_params *data);
t_point				find_spawnpoint(char **map);
int					game_loop(t_params *data);
int					check_map(t_params *params);
void				identifier_value(t_params *data,
						char *identifier, char *l, int i);
unsigned int		rgb_to_hex(int r, int g, int b);
int					close_window(t_params *data);
int					identifier_value_pos(char *str, char *search);
int					check_found(t_params *data);
int					check_colors(const int *error);
int					open_textures(t_params *data);
bool				create_window(t_params *data);
void				read_configuration(t_params *data);
void				open_map(t_params *data, char *file);
void				error_msg(char *error, char *str);
void				print_tab(char **arr);
void				ft_free_array(char **arr);
int					handle_rgb(char *str, int *error);
int					handle_rgb_helper(char **arr);
int					check_rgb_code(char *str);
int					parse_cub(t_params *data, char **argv);
char				*gnl_w_counter(t_params *data, int fd);
void				clean_exit(t_params *params, int exit_code);
char				**read_map(t_params *data);
char				*skip_nline(t_params *data);
void				check_nline(t_params *data, char *l, char *str);
char				**copy_and_equalize(t_params *data, char **a, int c);
void				put_color_msg(char *color, char *str);
int					turn_view(t_game *game, int keycode);
int					handle_key_event(int keycode, t_params *data);
void				init_events(t_params *data);
int					move_hor(t_params *data, int keycode);
int					move_ver(t_params *data, int keycode);
unsigned int		my_mlx_get_pixel_color(t_image image, int x, int y);
void				find_hit(t_params *data,
						double perp_wall_dist, t_point ray_dir);
void				fill_texture_buffer(t_params *data, int x, t_point ray_dir);
void				draw_minimap(t_params *data);
#endif
