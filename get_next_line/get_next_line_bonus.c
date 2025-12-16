/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:59:37 by addias            #+#    #+#             */
/*   Updated: 2025/11/20 14:59:38 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX];
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stack[fd]), NULL);
	temp = read_newline(fd, stack[fd]);
	if (!temp || !*temp)
		return (free(stack[fd]), stack[fd] = NULL, NULL);
	stack[fd] = temp;
	if (!stack[fd] || !*stack[fd])
		return (NULL);
	i = 0;
	while (stack[fd][i] && stack[fd][i] != '\n')
		i++;
	line = ft_substr(stack[fd], 0, i + 1);
	if (!line)
		return (free(stack[fd]), stack[fd] = NULL, NULL);
	stack[fd] = clean_old_stack(stack[fd]);
	if (stack[fd] && !*stack[fd])
	{
		return (free(stack[fd]), stack[fd] = NULL);
	}
	return (line);
}

