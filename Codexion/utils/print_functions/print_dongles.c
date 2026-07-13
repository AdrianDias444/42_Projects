#include "../../header.h"

void ft_print_dongles(t_circle* circle)
{
    t_coder* current_coder;
    t_dongle* current_dongle;
    
    current_coder = circle->first_coder;
    current_dongle = circle->first_coder->right_dongle;
    while(current_dongle != circle->first_coder->left_dongle)
    {
        printf("Current Coder is : %d | ", current_coder->number);
        printf("Left Dongle is: %c | ", current_coder->left_dongle->name);
        printf("Right Dongle is: %c \n", current_coder->right_dongle->name);
        current_coder = current_coder->next;
        current_dongle = current_dongle -> next;
    }
    printf("Current Coder is : %d | ", current_coder->number);
    printf("Left Dongle is: %c | ", current_coder->left_dongle->name);
    printf("Right Dongle is: %c \n", current_coder->right_dongle->name);
}


void ft_print_all_dongles(t_dongle* first_dongle, t_dongle* last_dongle, t_circle* circle)
{
    t_dongle* current;
    
    current = first_dongle;
    while(current != last_dongle)
    {
        printf("Current dongle is %c\n", current->name);
        current = current -> next;
    }
    printf("Current dongle is %c\n", circle->first_coder->left_dongle->name);
    (void) circle;
}