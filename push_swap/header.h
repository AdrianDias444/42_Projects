#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int nb;
    int index;
    int final_index;
    struct s_node *next;
    struct s_node *past;
} t_node;

int	ft_atoi(const char *nptr);
t_node *ft_to_stackA(int n, int i, t_node *addr);
void ft_print_node(t_node *first_node);
t_node *ft_sa(t_node *first_node);


#endif