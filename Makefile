NAME = checker
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = srcs/checker/main.c \
			srcs/checker/check_params.c \
			srcs/checker/stock_numbers.c \
			srcs/checker/ft_error.c \


OBJ_NAME = $(SRC_NAME:.c=.o)

LDLIBS = -Llibft

LDFLAGS = -lft

CPPFLAGS = -I./incs \
			-I./libft \

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo $(NAME) "\x1b[32m✔\x1b[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@$(RM) $(OBJ_NAME)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all
