NAME =	fdf

CC =	gcc
CFLAGS =	-g -Werror -Wextra -Wall -MMD 

RM =	rm -rf

SRC =	draw.c\
		read_file.c\
		main.c\
		get_next_line_utils.c\
		get_next_line.c\
		utils.c\

INCLUDE =	-I get_next_line.h\
			-I fdf.h\
			-I libft/libft.h\
			-I minilibx/mlx.h\

OBJ =	$(SRC:.c=.o)
D =		$(SRC:.c=.d)

LD_FLAGS =	-L libft -L minilibx

.PHONY :	all clean re fclean


$(NAME):	$(OBJ)
				make -C ./libft/
				$(CC) ${CFLAGS} ${LD_FLAGS} ${OBJ} ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ) $(D) get_next_line.o get_next_line.d get_next_line_utils.o get_next_line_utils.d
	make clean -C libft/
#	make clean -C minilibx/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/
#	make fclean -C minilibx/

re:			fclean all

-include $(D)