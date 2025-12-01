/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:26:34 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 14:54:19 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && i + len_dst < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_src + len_dst);
}
// int main(int argc, char **argv)
// {
// 	if(argc == 4)
// 	{
// 		char *dst = argv[1];

// 		const char *src = argv[2];
// 		size_t size = (size_t)ft_atoi(argv[3]);

// 		ft_strlcat(dst, src, size);
// 		printf("FT_STRLCAT: %s", dst);

// 	}
// }
