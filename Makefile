NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ${INCLUDES}

INCLUDES = ./includes/

SRC_DIR = ./src/

SRC_FILES = pipex.c \
			pipex_utils.c \
			ft_printf.c \
			ft_printf_utils.c

SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

IBJS = ${SRCS:.c=.o}

EXEC = a.out

all = $(NAME)

$(NAME): 

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

test: ${EXEC}

clean:

fclean: clean

re: fclean all

.PHONY: $(NAME) all clean fclean re
