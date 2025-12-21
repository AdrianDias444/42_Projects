/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:17:29 by addias            #+#    #+#             */
/*   Updated: 2025/12/20 12:17:30 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	long	n;
	int		i;

	n = nb;
	i = 0;
	if (nb < 0)
	{
		n = -n;
		write(1, "-", 1);
		i++;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i +=ft_putnbr_unsigned(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_puthex(unsigned long nb, char def)
{
	char	*hex;
	int		i;

	i = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	hex = "0123456789abcdef";
	if (def == 'X')
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_puthex(nb / 16, def);
	i += ft_putchar(hex[nb % 16]);
	return (i);
}

/* int main(void)
{
	printf("| %d\n", ft_putnbr(1334));
} */
