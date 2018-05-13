NAME = checker
NAME2 = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_ALL =	srcs/parser/parse_params.c \
			srcs/parser/check_numbers.c \
			srcs/parser/check_duplicate.c \
			srcs/parser/stock_numbers.c \
			srcs/parser/create_piles.c \
			srcs/parser/pile_simplify.c \
			srcs/error/ft_error.c \
			srcs/checker/operation_getter.c \
			srcs/checker/do_operation.c \
			srcs/checker/sort_verifier.c \
			srcs/operations/swap.c \
			srcs/operations/push.c \
			srcs/operations/rotate.c \
			srcs/operations/reverse.c \
			srcs/push_swap/operations_algo.c \
			srcs/push_swap/issorted.c \

SRC_1 = srcs/checker/main.c \

SRC_2 = srcs/push_swap/main.c \

OBJ_ALL = $(SRC_ALL:.c=.o)
OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

LDLIBS = -Llibft

LDFLAGS = -lft

CPPFLAGS = -I./incs \
			-I./libft \

all: $(NAME)

$(NAME): $(OBJ_ALL) $(OBJ_1) $(OBJ_2)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ_ALL) $(OBJ_1) -o $(NAME)
	@echo $(NAME) "\x1b[32m✔\x1b[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ_ALL) $(OBJ_2) -o $(NAME2)
	@echo $(NAME2) "\x1b[32m✔\x1b[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@$(RM) $(OBJ_ALL) $(OBJ_1) $(OBJ_2)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME) $(NAME2)

re: fclean all
