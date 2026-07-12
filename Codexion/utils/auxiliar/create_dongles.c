#include "../../header.h"


t_dongle* create_single_dongle()
{
    t_dongle* new_dongle;

    new_dongle = malloc(sizeof(t_dongle));
    if (!new_dongle)
        return (NULL);
    return (new_dongle);
}

void ft_add_dongle_right(t_coder* coder, t_dongle* dongle)
{
    coder -> right_dongle = dongle;
}

void ft_add_dongle_left(t_coder* coder, t_dongle* dongle)
{
    coder -> left_dongle = dongle;
}

void ft_add_next_dongle(t_dongle* current_dongle, t_dongle* next_dongle)
{
    current_dongle->next = next_dongle;
}

// return the first dongle as a linked list
t_dongle* ft_create_dongles(t_circle* circle)
{
    t_coder* current_coder;
    t_dongle* current_dongle;
    t_coder* first_coder;
    t_dongle* first_dongle;
    char c;

    c = 'A';
    current_coder = circle->first_coder;
    first_coder = circle->first_coder;
    first_dongle = create_single_dongle();
    current_dongle = first_dongle;
    while(current_coder != first_coder->previous)
    {
        if(current_dongle != first_dongle)
            ft_add_next_dongle(first_dongle, current_dongle);
        current_dongle->name = c;
        ft_add_dongle_right(current_coder, current_dongle);
        current_coder = current_coder -> next;
        ft_add_dongle_left(current_coder, current_dongle);
        current_dongle = create_single_dongle();
        c++;

    }
    ft_add_dongle_right(current_coder, first_coder->left_dongle);
    ft_add_dongle_left(first_coder, current_dongle);


    return (first_coder->right_dongle);
}