NAME = fractol
NAME_LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c initialization.c events.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
MLX = -L ./lib/minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIBFT = -L ./libft -lft
INCLUDES = -I includes/ -I libft/includes/


all: 
	$(MAKE) -C ./libft
	$(MAKE) -C ./lib/minilibx_macos
	$(MAKE) $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIBFT)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./lib/minilibx_macos clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

norme:
	norminette $(SRC)
	norminette includes/fractol.h

re:	fclean all
