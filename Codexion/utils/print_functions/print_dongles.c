#include "../../header.h"

void ft_print_dongles(t_circle* circle)
{
    t_coder* current_coder;
    t_dongle* current_dongle;

    current_coder = circle->first_coder;
    current_dongle = circle->first_coder->right_dongle;
    while(current_dongle != current_coder->left_dongle)
    {
        printf("\n");
        printf("Current Coder is : %d | ", current_coder->number);
        printf("Right Dongle is: %c | ", current_coder->right_dongle->name);
        printf("Left Dongle is: %c \n", current_coder->left_dongle->name);
        current_coder = current_coder->next;
        current_dongle = current_dongle -> next;
    }
    printf("Current Coder is : %d | ", current_coder->number);
    printf("Right Dongle is: %c | ", current_coder->right_dongle->name);
    printf("Left Dongle is: %c \n", current_coder->left_dongle->name);
    printf("\n");

}