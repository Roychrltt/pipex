NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./src/

SRC_DIR = ./src/

SRC_FILES = pipex.c utils.c 
			
SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${SRCS:.c=.o}

EXEC = a.out

all = ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${CFLAGS} ${SRC} -L./libft -lft -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

test: ${EXEC}
	chmod 755 ${EXEC}

$(EXEC):
	${CC} ${CFLAGS} ${SRC}

clean:
	${MAKE} -C libft clean
	rm -rf ${OBJS}

fclean: clean
	${MAKE} -C libft fclean
	rm -rf ${NAME}
	rm -rf libft.a

re: fclean all

.PHONY: $(NAME) all clean fclean re
