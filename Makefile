NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

SRC_FILES = pipex.c utils.c 
			
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC:.c=.o)

SRC_BONUS_DIR = ./src_bonus/

SRC_BONUS_FILES = pipex_bonus.c pipex_utils_bonus.c pipex_utils1_bonus.c
			
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))

OBJS_BONUS = $(SRC_BONUS:.c=.o)

EXEC = a.out

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC libft
	@echo "$(GREEN)Program$(RESET) $(CYAN)$(BOLD)$(BLINK)pipex$(RESET) $(GREEN)creating!$(RESET)"
	@$(CC) $(CFLAGS) -I/src/ $(SRC) -L./libft -lft -o $(NAME)
	@echo "$(GREEN)Program$(RESET) $(CYAN)$(BOLD)pipex$(RESET) $(GREEN)created!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: $(EXEC)
	chmod 755 $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) $(SRC)

bonus: $(OBJS_BONUS)
	@$(MAKE) -sC libft
	$(MAKE) -sC libft
	@echo "$(GREEN)Program$(RESET) $(CYAN)$(BOLD)pipex(bonus)$(RESET) $(GREEN)creating!$(RESET)"
	@$(CC) $(CFLAGS) -I ./src_bonus/ $(SRC_BONUS) -L./libft -lft -o $(NAME)
	@echo "$(GREEN)Program$(RESET) $(CYAN)$(BOLD)pipex(bonus)$(RESET) $(GREEN)created!$(RESET)"

clean:
	@$(MAKE) -sC libft clean
	@$(MAKE) -sC libft clean
	@echo "$(GREEN)Cleaning up...$(RESET)"
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@echo "$(GREEN)Clean finished!$(RESET)"

fclean: clean
	@echo "$(GREEN)Fcleaning up...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf ./libft/libft.a
	@echo "$(GREEN)Fclean finished!$(RESET)"

re: fclean all

.PHONY: $(NAME) all clean fclean re bonus

# COLORS
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
BOLD = \033[1m
BLINK = \033[5m
RESET = \033[0m
