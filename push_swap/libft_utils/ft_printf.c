/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:30:34 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:02:38 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
		return (ft_putstr("(nil)"));
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

	if (!str)
		return (-1);
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
