#include "../header.h"


void ft_make_a_cicle(t_stack *a, t_stack *b)
{
    t_node *pivot = ft_return_mid(a);
    int count = ft_lst_size(a);
    int moved = 0;

    while (moved < count / 2)
    {
        if (a->top->nb <= pivot->nb)
        {
            if (!b->top || a->top->nb > b->top->nb)
            {
                pb(a, b);
            }
            else if (a->top->nb < ft_min_node(b)->nb)
            {
                while (b->top != ft_min_node(b))
                    rb(b);
                pb(a, b);
            }
            else
            {
                while (b->top->nb > a->top->nb)
                    rb(b);
                pb(a, b);
            }
            moved++;
        }
        else
            ra(a);
    }
    while (ft_max_node(b) != b->top)
        rrb(b);
}