NAME		= pipex

SRC			= src/test.c src/ft_split.c src/ft_strcmp.c src/ft_pipex.c

OBJ			= $(SRC:.c=.o)

RM			= /bin/rm -f

CFLAGS 		=
#CFLAGS 		= -Wall -Wextra -Werror

CC 			= gcc

.c.o:
			@$(CC) -c $< -o $(<:.c=.o)


all:		${NAME}


$(NAME):	${OBJ}
			@gcc -o ${NAME} ${OBJ}


clean:
			@$(RM) $(OBJ)


fclean:		clean
			@$(RM) $(NAME)


re:		fclean all

#.PONY		all clean fclean re
