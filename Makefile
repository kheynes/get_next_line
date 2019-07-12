NAME = get_next_line.a

SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

test:
	$(MAKE) -C libft/ fclean
	$(MAKE) -C libft/

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all
