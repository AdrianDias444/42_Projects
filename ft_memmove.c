/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:25:57 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 19:24:36 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return ((void *)d);
}

// int	main(void)
// {
// 	char	*src = NULL;
// 	//char	dest[30] = {0};
// 	char	test[30] = {0};
// 	memmove(test, src, ft_strlen(src) + 1);
// 	printf("   MEMMOVE: %s", test);
// 	//ft_memmove(dest, src, ft_strlen(src) + 1);
// 	//printf("\nFT_MEMMOVE: %s", dest);
// }
