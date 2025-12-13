#include "ft_printf.h"

void format(char c, char* va_arg)
{
    //printf("%c", c);
    if(c == 'c')
        ft_putchar(va_arg[0]);
    if(c == 's')
        ft_putstr(va_arg);
/*  if(c == 'p'){
    }
    if(c == 'd'){
    }
    if(c == 'i'){
    }
    if(c == 'u'){
    }
    if(c == 'x'){
    }
    if(c == 'X'){
    }
    if(c == '%'){
    } */

}





int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int j;

    i = 0;
    j = 0;
    va_start(args, str);
    while(str[i])
    {
        if(str[i] == '%')
        {
            format(str[++i], va_arg(args, char *));
            j++;
        }
        i++;
    }

    // printf("%s", va_arg(args, char *));
    // printf("\n%s", va_arg(args, char *));
    // printf("\n%s", str);

    va_end(args);
    return(1);
}

int main(void)
{
    ft_printf("dad%cd%sd", "a", "fddsfl");
}