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

void ft_putnbr(int nb)
{
    long n = nb;

    if(nb < 0)
    {
        n = -n;
        write(1, "-", 1);
    }
    if(n > 9)
        ft_putnbr(n / 10);
    ft_putchar((n % 10)  + '0');
}

void ft_putnbr_unsigned(unsigned int nb)
{
    if(nb > 9)
        ft_putnbr_unsigned(nb /10);
    ft_putchar((nb % 10) + '0');
}


void ft_puthex(unsigned long nb, char def)
{
    char *hex;

    if (nb == 0)
    {
        ft_putchar('0');
        return ;
    }
    hex = "0123456789abcdef";

    if(def == 'X')
        hex = "0123456789ABCDEF";
    if(nb >= 16)
        ft_puthex(nb / 16, def);
    ft_putchar(hex[nb % 16]);    
}