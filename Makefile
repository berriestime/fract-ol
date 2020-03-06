NAME = fractol
NAME_LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
MLX = -L./lib/minilibx_macos -lm -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I includes/
HEADER = ./includes/fractol.h

$(NAME): $(OBJ) $(HEADER)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(MLX) 

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

all: 
	$(MAKE) -C ./libft
	$(MAKE) $(NAME)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

norme:
	norminette $(SRC)
	norminette includes/fractol.h

re:	fclean all