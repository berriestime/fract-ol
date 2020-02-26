NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
MLX = -L./lib/minilibx_macos -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(MLX)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@   

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all