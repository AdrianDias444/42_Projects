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
    return (str);
}


t_args ft_parser(int argc, char** argv)
{
    t_args args;

    if (argc != 9)
    {
        printf("Invalid number of parameters");
        return args;
    }
    args.number_of_coders = handle_number(argv[1]);
    args.time_to_burnout = handle_number(argv[2]);
    args.time_to_compile = handle_number(argv[3]);
    args.time_to_debug = handle_number(argv[4]);
    args.time_to_refactor = handle_number(argv[5]);
    args.number_of_compiles_required = handle_number(argv[6]);
    args.dongle_cooldown = handle_number(argv[7]);
    args.scheduler = handle_string(argv[8]);
    return args;
}