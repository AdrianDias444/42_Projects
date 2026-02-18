# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: addias <addias@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 11:27:20 by addias            #+#    #+#              #
#    Updated: 2026/02/17 11:35:04 by addias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SOURCES = libft_utils/ft_atoi.c\
libft_utils/ft_split.c\
libft_utils/ft_strlcpy.c\
libft_utils/ft_strlen.c\
libft_utils/ft_substr.c\
libft_utils/ft_strdup.c\
libft_utils/ft_printf.c\
libft_utils/ft_printf_utils.c\
mv_utils/ft_create_node.c\
mv_utils/ft_stack_init.c\
mv_utils/ft_stack_pop.c\
mv_utils/ft_stack_push.c\
mv_utils/ft_stack_push_back.c\
mv_utils/ft_stack_pop_back.c\
utils/ft_print_stack.c\
utils/ft_last_node.c\
utils/ft_lst_size.c\
utils/ft_is_in_middle.c\
utils/ft_is_ordered.c\
utils/ft_min_node.c\
utils/ft_max_node.c\
utils/ft_calc_cost.c\
utils/ft_sort_3_elem.c\
utils/ft_free_stack.c\
mv_rules/sa.c mv_rules/sb.c mv_rules/ss.c\
mv_rules/pa.c mv_rules/pb.c\
mv_rules/ra.c mv_rules/rb.c mv_rules/rr.c\
mv_rules/rra.c mv_rules/rrb.c mv_rules/rrr.c\
quick_sort/ft_quick_sort.c\
quick_sort/ft_return_mid.c\
quick_sort/ft_dup_stack.c\
quick_sort/ft_remove_this_node.c\
quick_sort/ft_make_a_cicle.c\
quick_sort/ft_more_under_pivot.c\
quick_sort/ft_find_place.c\
quick_sort/ft_insert_node.c\
quick_sort/ft_min_below.c\
quick_sort/ft_return_mid_mid.c\
parser/ft_parser.c\
parser/ft_is_a_string.c\
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