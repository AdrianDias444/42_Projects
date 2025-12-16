#include "ft_printf.h"


int ft_spec(char c)
{
    if(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return(1);
    return(0);
}

int ft_ptr_adrr(void *ptr)
{
    size_t adress;
    
    if(!ptr)
    {
        ft_putstr("(nill)");
        return (-1);
    }
    adress = (size_t)ptr;
    ft_putstr("0x");
    return(ft_puthex(adress, 'x') + 2);
}

int format(char c, va_list args, int i)
{

    //printf("%c", c);
    if(c == 'c')
        return(ft_putchar(va_arg(args, int)));
    if(c == 's')
        return(ft_putstr(va_arg(args, char *)));
    if(c == 'p')
    {
        void *ptr = va_arg(args, void *);
        return(ft_ptr_adrr(ptr));
    }
    if(c == 'd')
        return(ft_putnbr(va_arg(args, int)));
    if(c == 'i')
        return(ft_putnbr(va_arg(args, int)));
    if(c == 'u')
        return(ft_putnbr_unsigned(va_arg(args,  unsigned int)));
    if(c == 'x')
        return(ft_puthex(va_arg(args, unsigned int), 'x'));
    if(c == 'X')
        return(ft_puthex(va_arg(args, unsigned int), 'X'));
    if(c == '%')
        return(ft_putchar('%'));
    return(i+2);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int arg;
    int len;

    i = 0;
    arg = 0;
    len = 0;
    va_start(args, str);
    while(str[i])
    {
        if(str[i] == '%' && ft_spec(str[i + 1]))
        {
            len +=format(str[i + 1], args, i);
            arg++;
            i +=2;
        }
        else
            ft_putchar(str[i++]);
    }
    va_end(args);
    return(len + i - 2*arg);
}

int main(void)
{
    ft_printf("My function | Test %s my %s printf %% part %u\n", "for", "own", -3);
    printf("Printf Base | Test %s my %s printf %% part %u\n", "for", "own", -3);
    //int number = 259;    
    
    printf("%i Testing now\n", printf("\n\nPrintf Base | %u | ", 25945567));
    ft_printf("%i Testing now\n", ft_printf("My function | %u | ", 25945567));
    
    //void *s = "string";
    //char *str = (char *)s;

}
