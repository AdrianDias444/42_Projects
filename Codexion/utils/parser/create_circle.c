#include "../../header.h"


t_circle* ft_create_circle(t_coder* coder, t_args args)
{
    t_circle* circle;

    circle = malloc(sizeof(t_circle));
    if (!circle)
        return (NULL);
    circle -> first_coder = coder;
    circle -> number_of_coders = args.number_of_coders;
    circle -> nb_dongles = args.number_of_coders;

    return (circle);
}