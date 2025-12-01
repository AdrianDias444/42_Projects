/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:25:47 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 18:55:23 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len = 1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		space;
	long	nb;

	nb = n;
	space = ft_int_len(n);
	str = malloc(sizeof(char) * (space + 1));
	if (!str)
		return (NULL);
	str[space] = '\0';
	space--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (space > 0)
	{
		str[space] = (nb % 10) + '0';
		nb = nb / 10;
		space--;
	}
	if (n >= 0)
		str[space] = nb + '0';
	return (str);
}

// int main()
// {
// 	int n = -623;
// 	char *resultado = ft_itoa(n);

// 	printf("%d\n", ft_int_len(n));
// 	printf("%s", resultado);
// 	printf("\n");

// 	free(resultado);
// }
