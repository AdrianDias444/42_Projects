#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>



int ft_printf(const char *arg, ...);

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int nb);
int ft_putnbr_unsigned(unsigned int nb);
int ft_puthex(unsigned long nb, char def);


#endif
