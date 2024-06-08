NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = 

SRCS = 

IBJS = ${SRCS:.c=.o}

all = $(NAME)

$(NAME): 

%.o: %.c

clean:

fclean: clean

re: fclean all

.PHONY: $(NAME) all clean fclean re
