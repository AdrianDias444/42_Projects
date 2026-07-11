#include "../header.h"

void ft_add_previous_coder(t_coder* current_coder, t_coder* previous_coder)
{
    current_coder -> previous = previous_coder;
}