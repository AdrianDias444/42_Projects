/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:17:22 by addias            #+#    #+#             */
/*   Updated: 2025/12/20 12:17:23 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_ptr_adrr(void *ptr)
{
	size_t	adress;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	adress = (size_t)ptr;
	ft_putstr("0x");
	return (ft_puthex(adress, 'x') + 2);
}

int	ft_format(char c, va_list args)
{
	void	*ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		ptr = va_arg(args, void *);
		return (ft_ptr_adrr(ptr));
	}
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_spec(str[i + 1]))
		{
			total_len += ft_format(str[i + 1], args);
			i += 2;
		}
		else
			total_len += ft_putchar(str[i++]);
	}
	va_end(args);
	return (total_len);
}
/* int main(void)
{

	ft_putstr("====== PRINTF TESTER ======\n\n");
	ft_putstr("#########################\n");
	ft_putstr("###### TEST FOR %c ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");

	char a = 'a';
	printf(" RETURNED VALUE | %d\n",printf("PRINTF BASE | %c", a));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %c", a));
	ft_putstr("-------------------------\n");
	
    char b = 'b';
	printf(" RETURNED VALUE | %d\n",printf("PRINTF BASE | %c", b));
	ft_printf(" RETURNED VALUE | %d\n",ft_printf("MY FUNCTION | %c", b));
	ft_putstr("------------------------\n");
	
    char c = ' ';
	printf(" RETURNED VALUE | %d\n",printf("PRINTF BASE | %c", c));
	ft_printf(" RETURNED VALUE | %d\n",ft_printf("MY FUNCTION | %c", c));
	ft_putstr("------------------------\n");


	ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %s ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    char *str = NULL;
	printf(" RETURNED VALUE | %d\n",printf("PRINTF BASE | %s", str));
	ft_printf(" RETURNED VALUE | %d\n",ft_printf("MY FUNCTION | %s", str));
	ft_putstr("-------------------------\n");
	
    char *str2 = "Testing";
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %s", str2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %s", str2));
	ft_putstr("-------------------------\n");
	
    char *str3 = "Printf is not working";
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %s", str3));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %s", str3));
	
    
    ft_putstr("-------------------------\n");
	ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %p ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    char *ptr = "NULL";
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %p", ptr));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %p", ptr));
	ft_putstr("-------------------------\n");
	
    char *ptr2 = NULL;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %p", ptr2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %p", ptr2));
	ft_putstr("-------------------------\n");
    
    int ptr3[12];
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %p", ptr3));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %p", ptr3));
	
    
    ft_putstr("-------------------------\n");
	ft_putstr("\n################################\n");
	ft_putstr("###### TEST FOR %d and %i ######\n");
	ft_putstr("################################\n\n");
	ft_putstr("-------------------------\n");
	
    int nb = 23;
	ft_putstr("%d\n");
	printf(" RETURNED VALUE | %d\n",printf("PRINTF BASE | %d", nb));
	ft_printf(" RETURNED VALUE | %d\n",ft_printf("MY FUNCTION | %d", nb));
	ft_putstr("-------------------------\n");
	
    long n = 20000000000000000;
	ft_putstr("%d\n");
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %d", n));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %d", n));
	ft_putstr("-------------------------\n");
	
    int nb2 = 23;
	ft_putstr("%i\n");
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %d", nb2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %d", nb2));
	ft_putstr("-------------------------\n");
	
    long n2 = 20000000000000000;
	ft_putstr("%i\n");
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %d", n2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %d", n2));
	ft_putstr("-------------------------\n");
	
    ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %u ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    int u = 12;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %u", u));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %u", u));
	ft_putstr("-------------------------\n");
	
    int u1 = 0;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %u", u1));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %u", u1));
	ft_putstr("-------------------------\n");
	
    int u2 = -2;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %u", u2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %u", u2));
	ft_putstr("-------------------------\n");
	
    
    ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %x ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    int hex = 12;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %x", hex));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %x", hex));
	ft_putstr("-------------------------\n");
	
    int hex2 = 42000;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %x", hex2));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %x", hex2));
	ft_putstr("-------------------------\n");
	
    int hex3 = 367906;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %x", hex3));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %x", hex3));
	ft_putstr("-------------------------\n");
	
    
    ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %X ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    int hex_U = 12;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %X", hex_U));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %X", hex_U));
	ft_putstr("-------------------------\n");
	
    int hex2_U = 42000;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %X", hex2_U));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %X", hex2_U));
	ft_putstr("-------------------------\n");
	
    int hex3_U = 367906;
	printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %X", hex3_U));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %X", hex3_U));
	ft_putstr("-------------------------\n");
    
    ft_putstr("\n#########################\n");
	ft_putstr("###### TEST FOR %% ######\n");
	ft_putstr("#########################\n\n");
	ft_putstr("-------------------------\n");
	
    printf(" RETURNED VALUE | %d\n", printf("PRINTF BASE | %%"));
	ft_printf(" RETURNED VALUE | %d\n", ft_printf("MY FUNCTION | %%"));
}
 */