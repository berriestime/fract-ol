NAME = fractol
FLAGS = -g -pg
SRC = $(wildcard src/*.c)
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