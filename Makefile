NAME = checker
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME = srcs/checker/main.c \
			srcs/checker/parse_params.c \
			srcs/checker/check_numbers.c \
			srcs/checker/check_duplicate.c \
			srcs/checker/stock_numbers.c \
			srcs/checker/create_piles.c \
			srcs/checker/pile_simplify.c \
			srcs/checker/ft_error.c \
			srcs/checker/operation_getter.c \
			srcs/checker/do_operation.c \
			srcs/checker/sort_verifier.c \
			srcs/operations/swap.c \
			srcs/operations/push.c \
			srcs/operations/rotate.c \
			srcs/operations/reverse.c \

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
