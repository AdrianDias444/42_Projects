#include "../header.h"

void ft_print_coders(t_coder* first_coder)
{
    t_coder* current_coder;

    current_coder = first_coder;
    while(current_coder != first_coder->previous)
    {
        printf("Current Coders is %d, Next Coder: %d, Previous One: %d\n", current_coder->number, current_coder->next->number, current_coder->previous->number);
        current_coder = current_coder->next;
    }
    printf("Current Coders is %d Next Coder: %d, Previous One: %d\n", current_coder->number, current_coder->next->number, current_coder->previous->number);

}