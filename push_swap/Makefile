NAME = push_swap.a

SOURCES = libft_utils/ft_atoi.c\
mv_utils/ft_create_node.c\
mv_utils/ft_stack_init.c\
mv_utils/ft_stack_pop.c\
mv_utils/ft_stack_push.c\
mv_utils/ft_stack_push_back.c\
mv_utils/ft_stack_pop_back.c\
utils/ft_print_stack.c\
utils/ft_last_node.c\
mv_rules/sa.c mv_rules/sb.c mv_rules/ss.c\
mv_rules/pa.c mv_rules/pb.c\
mv_rules/ra.c mv_rules/rb.c mv_rules/rr.c\
mv_rules/rra.c mv_rules/rrb.c mv_rules/rrr.c\
push_swap.c

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