/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:59:52 by addias            #+#    #+#             */
/*   Updated: 2025/11/20 14:59:53 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*read_newline(int fd, char *stack)
{
	char	*buffer;
	int		bytes_lidos;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_lidos = 1;
	while (bytes_lidos > 0)
	{
		bytes_lidos = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lidos <= 0)
			break ;
		buffer[bytes_lidos] = '\0';
		stack = ft_strjoin(stack, buffer);
		while (stack[i])
		{
			if (stack[i] == 10)
				return (free(buffer), stack);
			i++;
		}
	}
	free(buffer);
	return (stack);
}

char	*clean_old_stack(char *stack)
{
	int		i;
	char	*new_stack;

	if (!stack || !*stack)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	if (!stack[i])
		return (free(stack), NULL);
	new_stack = ft_substr(stack, i, ft_strlen(stack) - i);
	free(stack);
	return (new_stack);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	len_ind;

	len_ind = len + start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1 || !*s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i++])
		str[i] = s1[i];
	j = 0;
	while (s2[j++])
		str[i + j] = s2[j];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), str);
}
