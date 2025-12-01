/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:38:11 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 14:19:26 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		((char *)d)[i] = ((const char *)s)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	// char	src[] = "Hello world";
// 	// char	dest[10] = {0};
// 	// char	teste[10] = {0};

// 	int a = 200;
// 	int b = 10;
// 	printf("Antes: src = %d, dest = %d\n\n", b, a);
// 	ft_memcpy(&a, &b, 4);
// 	memcpy(&a, &b, 4);
// 	printf("FT_MEMCPY: src = %d, dest = %d\n", b, a);
// 	printf("   MEMCPY: src = %d, dest = %d\n", b, a);
// 	return (0);
//}
