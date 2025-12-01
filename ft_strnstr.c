/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:04:51 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 15:33:56 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
			j++;
		if (j == ft_strlen(little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 		const char *big = argv[1];
// 		const char *little = argv[2];
// 	size_t	len;

// 	if(argc == 4)
// 	{
// 		len = (size_t)ft_atoi(argv[3]);
// 		printf("FT_STRNSTR: %s", ft_strnstr(big, little, len));
// 	}
// }
