/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:24:44 by addias            #+#    #+#             */
/*   Updated: 2025/10/31 15:47:57 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	negativo;
	int	res;

	signal = 0;
	negativo = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		signal++;
		if (signal > 1)
			return (0);
		if (*nptr == '-')
			negativo = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * negativo);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "\007 8";
// 	printf("   ATOI: %d \nFT_ATOI: %d", atoi(str), ft_atoi(str));
// }
