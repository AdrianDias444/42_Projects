#include "../../header.h"


t_circle* ft_handle_circle(t_args args)
{
    int i;
    t_coder* first_coder;
    t_coder* current_coder;
    t_coder* next_coder;
    t_circle* circle;

    first_coder = ft_create_coder(1);
    current_coder = first_coder;
    i = 2;
    while(i <= args.number_of_coders)
    {
        next_coder = ft_create_coder(i);
        ft_add_next_coder(current_coder, next_coder);
        ft_add_previous_coder(next_coder, current_coder);
        current_coder = next_coder;
        i++;
    }
    current_coder -> next = first_coder;
    first_coder -> previous = current_coder;
    circle = ft_create_circle(first_coder, args);

    return(circle);
}