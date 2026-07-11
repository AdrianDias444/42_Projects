#include "header.h"

int handle_number(char* str)
{
    int nb;
    
    nb = atoi(str);
    if (nb == 0)
        return -1;
    else
        return nb;
}

char* handle_string(char* str)
{
    if (strcmp(str, "edf") != 0 && strcmp(str, "fifo") != 0)
        return (NULL);
    return (str);
}


t_args ft_parser(void)
{
    t_args args;
    args.number_of_coders = NUMBER_OF_CODERS;
    args.time_to_burnout = TIME_TO_BURNOUT;
    args.time_to_compile = TIME_TO_COMPILE;
    args.time_to_debug = TIME_TO_DEBUG;
    args.time_to_refactor = TIME_TO_REFACTOR;
    args.number_of_compiles_required = NUMBER_OF_COMPILES_REQUIRED;
    args.dongle_cooldown = DONGLE_COOLDOWN;
    args.scheduler = handle_string(SCHEDULER);
    return args;
}


t_coder* ft_create_coders(t_args args)
{
    int i;
    int nb_coders;
    t_coder* first_coder;
    t_coder* current_coder;
    t_coder* next_coder;

    first_coder = ft_create_coder(1);
    current_coder = first_coder;
    i = 2;
    nb_coders = args.number_of_coders;
    while(i <= nb_coders)
    {
        next_coder = ft_create_coder(i);
        ft_add_next_coder(current_coder, next_coder);
        ft_add_previous_coder(next_coder, current_coder);
        current_coder = next_coder;
        i++;
    }
    current_coder -> next = first_coder;
    first_coder -> previous = current_coder;

    return(first_coder);
}