NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c stack.c input.c sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all