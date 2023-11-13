SRCS = man/main.c man/inits.c man/window_graphics.c man/events.c
OBJS = $(SRCS:.c=.o)

BONUS =
BONUS_OBJS = $(BONUS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -I libft/
LIBFT_DIR		= libft
MINILIBX_DIR	= minilibx
LIBFT			= $(LIBFT_DIR)/libft.a
MINILIBX		= $(MINILIBX_DIR)/libmlx.a
LIBS			= -L$(LIBFT_DIR) -lft
MLIBX			= -L$(MINILIBX_DIR) -lmlx

NAME = cub3D

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@ $(MAKE) -C $(MINILIBX_DIR) >/dev/null 2>&1

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLIBX) -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBS)

.PHONY: all clean fclean bonus re

