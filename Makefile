CC = cc 

CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft -g

NAME = fractol
 
SRC = src/colours.c src/fractol_init.c src/fractol_utils1.c src/fractol_utils2.c \
      src/fractol_utils3.c src/fractol.c src/fractol_render.c\

LIB = lib/src

MLX = mlx_linux

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)/libft.a $(MLX)libmlx.a $(MLX)/libmlx_Linux.a 
	@$(CC) $(OBJ) -L$(LIB) -lft -L$(MLX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(LIB)/libft.a:
	@echo "Compiling Libft..."
	@make -C $(LIB)

$(MLX)/libmlx_Linux.a $(MLX)libmlx.a:
	@echo "Compiling MLX..."
	@cd $(MLX) && ./configure
	@make -C $(MLX)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@make clean -C $(LIB)
	@make clean -C $(MLX)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB)
	@make clean -C $(MLX)
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
