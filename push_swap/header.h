#ifndef HEADER_H
#define HEADER_H

//----------------------
// Includes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//----------------------
// Structs
typedef struct s_node
{
    int nb;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;
//----------------------
// My functions

int	ft_atoi(const char *nptr);

t_node *ft_create_node(int value);
void ft_stack_init(t_stack *stack);
void ft_stack_push(t_stack *stack, t_node *node);
t_node *ft_stack_pop(t_stack *stack);

void ft_print_stack(t_stack *stack);

#endif