#include "../../header.h"

void ft_print_circle(t_coder* first_coder)
{
    t_coder* current_coder;

    current_coder = first_coder;
    while(current_coder != first_coder->previous)
    {
        printf("Current Coder is %d, Next Coder: %d, Previous One: %d\n", current_coder->number, current_coder->next->number, current_coder->previous->number);
        current_coder = current_coder->next;
    }
    printf("Current Coder i %d Next Coder: %d, Previous One: %d\n", current_coder->number, current_coder->next->number, current_coder->previous->number);
    printf("\n");

}