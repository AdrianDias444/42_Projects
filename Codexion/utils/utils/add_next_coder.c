#include "../../header.h"

void ft_add_next_coder(t_coder* current, t_coder* next)
{
    current -> next = next;
}