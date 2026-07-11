#include "../header.h"

void ft_add_next_coder(t_coder* current_coder, t_coder* next_coder)
{
    current_coder -> next = next_coder;
}