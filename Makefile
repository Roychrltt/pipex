NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

SRC_FILES = pipex.c utils.c 
			
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC:.c=.o)

SRC_BONUS_DIR = ./src_bonus/

SRC_BONUS_FILES = pipex_bonus.c pipex_utils_bonus.c \
				  line_bonus.c line_utils_bonus.c
			
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))

OBJS_BONUS = $(SRC_BONUS:.c=.o)

EXEC = a.out

all = $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -I ./src/ $(SRC) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(EXEC)
	chmod 755 $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) $(SRC)

bonus: $(OBJS_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -I ./src_bonus/ $(SRC_BONUS) -L./libft -lft -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)
	rm -rf libft.a

re: fclean all

.PHONY: $(NAME) all clean fclean re bonus
