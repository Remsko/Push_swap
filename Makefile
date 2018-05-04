NAME = 
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC_NAME =

OBJ_NAME = $(SRC_NAME:.c=.o)

LDLIBS =

CPPFLAGS = -I./incs \
		   -I./libft \

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@ar -rc $(NAME) $(OBJ_NAME)
	@echo $(NAME) "\x1b[32m✔\x1b[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ_NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
