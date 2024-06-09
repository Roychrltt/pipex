NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./src/

SRC_DIR = ./src/

SRC_FILES = pipex.c utils.c 
			
SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${SRCS:.c=.o}

EXEC = a.out

all = $(NAME)

$(NAME): 

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

test: ${EXEC}
	chmod 755 ${EXEC}

$(EXEC):
	${CC} ${CFLAGS} ${SRC}

clean:
	rm -rf a.out

fclean: clean

re: fclean all

.PHONY: $(NAME) all clean fclean re
