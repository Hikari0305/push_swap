NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = main.c utils.c parse_args.c ft_isdigit.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c operations.c validation.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
