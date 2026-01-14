#include "../header.h"


void ft_make_a_cicle(t_stack *a, t_stack *b)
{
    t_node *pivot;
    
    pivot = ft_return_mid(a);
    while (ft_min_node(a)->nb <= pivot->nb)
    {
        if (a->top->nb <= pivot->nb)
        {
            if(b->top && b->top->next)
                if(b->top->nb < b->top->next->nb)
                    sb(b);
            
            while(b->top && a->top->nb < b->top->nb && a->top->nb > ft_min_node(b)->nb)
                rb(b);
            
            if(!b->top || !b->top->next)
                pb(a, b);
            else if(b->top && b->top->next)
                pb(a, b);
            if(b->top && b->top == ft_min_node(b))
                rb(b);

        }
        else
            ra(a);
    }
    while (ft_max_node(b) != b->top)
        rrb(b);
}