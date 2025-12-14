#include "ft_printf.h"


int ft_spec(char c)
{
    if(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return(1);
    return(0);
}

void ft_ptr_adrr(void *ptr)
{
    size_t adress;
    
    if(!ptr)
    {
        ft_putstr("(nill)");
        return ;
    }
    adress = (size_t)ptr;
    ft_putstr("0x");
    ft_puthex(adress, 'x');
}

int format(char c, va_list args, int i)
{

    //printf("%c", c);
    if(c == 'c')
        ft_putchar(va_arg(args, int));
    if(c == 's')
        ft_putstr(va_arg(args, char *));
    if(c == 'p')
    {
        void *ptr = va_arg(args, void *);
        ft_ptr_adrr(ptr);
    }
    if(c == 'd')
        ft_putnbr(va_arg(args, int));
    if(c == 'i')
        ft_putnbr(va_arg(args, int));
    if(c == 'u')
        ft_putnbr_unsigned(va_arg(args,  unsigned int));
    if(c == 'x')
        ft_puthex(va_arg(args, unsigned int), 'x');
    if(c == 'X')
        ft_puthex(va_arg(args, unsigned int), 'X');
    if(c == '%')
        ft_putchar('%');
    return(i+2);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;

    i = 0;
    va_start(args, str);
    while(str[i])
    {
        if(str[i] == '%' && ft_spec(str[i + 1]))
            i = format(str[i + 1], args, i);
        else
            ft_putchar(str[i++]);
    }
    va_end(args);
    return(1);
}

int main(void)
{
    // ft_printf("My function | Test %s my %s printf %% part %u\n", "for", "own", -3);
    // printf("Printf Base | Test %s my %s printf %% part %u\n", "for", "own", -3);
    int number = 25923128;    
    
    ft_printf("  %p\n", number);
    printf("  %p\n", number);

    void *s = "string";
    char *str = (char *)s;


    //printf("%X\n", number);


/*     unsigned int number = -3;
    printf("%d", number);
 */

    // printf("%p\n", s);

    //printf("%u\n", -2);
    // printf("%i\n", 255555);
    // ft_putnbr(255555);
}
