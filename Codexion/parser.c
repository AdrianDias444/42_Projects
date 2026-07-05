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



t_args ft_parser(int argc)
{
    t_args args;

    // if (argc != 9)
    // {
    //     printf("Invalid number of parameters");
    //     return ;
    // }
    args.number_of_coders = handle_number("12");
    return args;
}

int main(void)
{
    t_args args;
    args = ft_parser(9);
    printf("%d", args.number_of_coders);
}