NAME		= so_long
NAMEBONUS	= so_long_bonus

SRC		=	main.c \
			map_checks.c \
			exit.c \
			parse_ber.c \
			map_check_symbols.c\
			map_check_path.c\
			parse_xpm.c\
			event_key.c\
			render.c\

OBJ	= $(addprefix ./obj/,$(SRC:.c=.o))

SRCBONUS	=	main_bonus.c \
				map_checks_bonus.c \
				exit_bonus.c \
				parse_ber_bonus.c \
				map_check_symbols_bonus.c\
				map_check_path_bonus.c\
				parse_xpm_bonus.c\
				event_key_bonus.c\
				render_bonus.c\

OBJBONUS	= $(addprefix ./obj_bonus/,$(SRCBONUS:.c=.o))

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
	$(CC) $(CFLAGS) $(LIBINCL) $(MLXINCL) -Iinclude/ -o $@ -c $<

$(LIBFTA):
	make -C ./libft

$(MLXA):
	make -C ./mlx

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK) $(MLXLINK)


bonus : obj_bonus $(LIBFTA) $(MLXA) $(NAMEBONUS)

obj_bonus:
	mkdir -p ./obj_bonus/

./obj_bonus/%.o:./src_bonus/%.c
	$(CC) $(CFLAGS) $(LIBINCL) $(MLXINCL) -Iinclude_bonus -o $@ -c $<

$(NAMEBONUS): $(OBJBONUS)
	$(CC) -o $(NAMEBONUS) $(OBJBONUS) $(LIBLINK) $(MLXLINK)


clean:
	rm -rf ./obj/ ./obj_bonus
	make -C ./libft clean
	make -C ./mlx clean

fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	make -C ./libft fclean
	make -C ./mlx clean

re: 		fclean all

.PHONY:		all clean fclean re
