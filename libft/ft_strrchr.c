/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:27:25 by addias            #+#    #+#             */
/*   Updated: 2025/11/01 15:10:23 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s = "ed     sdsdadc";

// 	int c = '\0';
// 	printf("FT_STRRCHR: %s\n", ft_strrchr(s, c));
// 	printf("   STRRCHR: %s", strrchr(s, c));
// }
