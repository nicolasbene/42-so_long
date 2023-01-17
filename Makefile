NAME	= so_long

SRC		=	main.c \
			map_checks.c \
			exit.c \
			parse_ber.c \
			map_check_symbols.c\
			map_check_path.c\
			parse_xpm.c\
			render.c\

OBJ	= $(addprefix ./obj/,$(SRC:.c=.o))

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL	= -I./libft
LIBLINK	= -L./libft -lft

MLXA	= ./mlx/libmlx.a
MLXINCL	= -I./mlx
MLXLINK	= -Lmlx -lmlx -Imlx -Lmlx -lm -lbsd -lX11 -lXext

all: obj $(LIBFTA) $(MLXA) $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	$(CC) $(CFLAGS) $(LIBINCL) $(MLXINCL) -Iinclude -o $@ -c $<

$(LIBFTA):
	make -C ./libft

$(MLXA):
	make -C ./mlx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK) $(MLXLINK) -g3

clean:
	rm -rf ./obj/
	make -C ./libft clean
	make -C ./mlx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./mlx clean

re: 		fclean all

.PHONY:		all clean fclean re
