NAME = push_swap.a

SOURCES = libft_utils/ft_atoi.c mv_utils/ft_create_node.c mv_utils/ft_stack_init.c\
mv_utils/ft_stack_pop.c mv_utils/ft_stack_push.c utils/ft_print_stack.c push_swap.c

OBJECTS = $(SOURCES:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPRESS = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPRESS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re