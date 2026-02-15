/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:30 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:36:57 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//----------------------
// Includes
//#include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//----------------------
// Structs
typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

//////////////////////////////////////////////////////////
// Libft functions

long long			ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);

int					ft_printf(const char *str, ...);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int nb);
int					ft_putnbr_unsigned(unsigned int nb);
int					ft_puthex(unsigned long nb, char def);
//////////////////////////////////////////////////////////
// mv_utils
t_node				*ft_create_node(long long value);
void				ft_stack_init(t_stack *stack);
void				ft_stack_push(t_stack *stack, t_node *node);
t_node				*ft_stack_pop(t_stack *stack);
void				ft_stack_push_back(t_stack *stack, t_node *node);
t_node				*ft_stack_pop_back(t_stack *stack);

//////////////////////////////////////////////////////////
// utils
void				ft_print_stack(t_stack *stack);
t_node				*ft_last_node(t_stack *stack);
int					ft_lst_size(t_stack *stack);
int					ft_is_in_middle(t_stack *stack, t_node *node);
int					ft_is_ordered(t_stack *stack);
t_node				*ft_min_node(t_stack *stack);
t_node				*ft_max_node(t_stack *stack);
int					ft_calc_cost(t_stack *stack, t_node *node_to_calc);
void				ft_sort_3_elem(t_stack *stack_A);
void				ft_free_stack(t_stack *stack);

//////////////////////////////////////////////////////////
// mv_rules
void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_A, t_stack *stack_B);
void				pa(t_stack *stack_B, t_stack *stack_A);
void				pb(t_stack *stack_A, t_stack *stack_B);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack_A, t_stack *stack_B);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack_A, t_stack *stack_B);

//////////////////////////////////////////////////////////
// quick_sort
void				ft_quick_sort(t_stack *stack_A, t_stack *stack_B);
t_node				*ft_return_mid(t_stack *stack);
t_stack				ft_dup_stack(t_stack *stack);
t_node				*ft_remove_this_node(t_stack *stack, t_node *node_to_del);
void				ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B);
int					ft_more_under_pivot(t_stack *stack, t_node *pivot);
int					ft_find_place(t_stack *stack, t_node *node_to_insert);
void				ft_insert_node(t_stack *stack_A, t_stack *stack_B);
t_node				*ft_min_bellow(t_stack *stack_B, t_node *node_to_calc);
t_node				*ft_return_mid_mid(t_stack *stack);
//////////////////////////////////////////////////////////
// parser
void				ft_parser(int argc, char **argv, t_stack *stack_A);
int					ft_is_a_string(char *str);

#endif