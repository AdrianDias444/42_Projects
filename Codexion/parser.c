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

t_args ft_parser()
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