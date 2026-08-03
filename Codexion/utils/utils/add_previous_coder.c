#include "../../header.h"

void ft_add_previous_coder(t_coder* current, t_coder* previous)
{
    current -> previous = previous;
}