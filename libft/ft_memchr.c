/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:25:34 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 15:23:59 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ptr;
	size_t			i;

	a = (unsigned char)c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == a)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	size_t	n;
// 	int		i;

// 	const void *s = "My own memchr test";
// 	i = 32;
// 	n = 5;
// 	printf("FT_MEMCHR: %s\n", (char *)ft_memchr(s, i, n));
// 	printf("   MEMCHR: %s", (char *)memchr(s, i, n));

// }
