#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>



int ft_printf(const char *arg, ...);

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
void ft_putnbr_unsigned(unsigned int nb);
void ft_puthex(unsigned long nb, char def);


#endif
