#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_vars {
	void	*win;
	void	*mlx;
}	t_vars;

bool	create_window(t_vars *data);
int		handle_key_press(int keycode, t_vars *data);
int		close_window(t_vars *data);

#endif
