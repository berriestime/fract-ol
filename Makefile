NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
MLX = -L./lib/minilibx_macos -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I includes/

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(MLX) 

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all