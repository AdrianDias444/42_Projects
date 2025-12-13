#include "ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}