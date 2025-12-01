/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:25:42 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 15:27:04 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// int main()
// {
// 		const char *s1 = "My memcmp test";
// 		const char *s2 = "My memcmp  test";

// 		size_t n = 11;

// 		printf("FT_MEMCMP: %d\n", ft_memcmp(s1, s2, n));
// 		printf("   MEMCMP: %d\n", memcmp(s1, s2, n));
// }
