SRCS	=	errors.c pipex_data.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

H_SRC	=	pipex.h

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
			cc ${FLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			make -C ./libft_42
			mv ./libft_42/libft.a ./$(NAME)
			ar -rcs $@ $^

all: 		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ./libft_42

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re