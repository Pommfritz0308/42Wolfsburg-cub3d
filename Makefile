NAME	= cub3D

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall -g #-fsanitize=address
INC			=	-I ./libft/\
				-I ./mlx/\
				-I /usr/X11/include \
				-I ./incl

LFLAGS = -L/usr/X11/lib -lX11 -lXext -lm


MLX_PATH	= mlx/
MLX_NAME	= libmlx_Darwin.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)



SRC_PATH	= src/
SRC =	check_colors.c \
		check_map.c \
		clean_exit.c \
		dda.c \
 		events.c \
		game_loop.c \
 		inits.c \
		main.c \
    	minimap.c \
 		parser_config.c \
 		parser_config2.c \
		parser_map.c \
		stack.c \
 		utils.c \
		utils2.c \
		textures.c \
 		window_graphics.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@make -sC $(MLX_PATH) >/dev/null 2>&1
	@echo "$(COLOUR_GREEN)mlx ready$(END_COLOUR)"

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@echo "$(COLOUR_GREEN)libft ready$(END_COLOUR)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(LFLAGS) $(INC)
	@echo "$(COLOUR_GREEN)cub3D ready$(END_COLOUR)"

bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX_PATH)$(MLX_NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean bonus

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
END_COLOUR=\033[0m
