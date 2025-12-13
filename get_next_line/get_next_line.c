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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stack), NULL);
	temp = read_newline(fd, stack);
	if (!temp || !*temp)
		return (free(stack), stack = NULL, NULL);
	stack = temp;
	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	line = ft_substr(stack, 0, i + 1);
	if (!line)
		return (free(stack), stack = NULL, NULL);
	stack = clean_old_stack(stack);
	if (stack && !*stack)
	{
		return (free(stack), stack = NULL, line);
	}
	return (line);
}

// int	main(void)
// {
// 	char	*fileName;
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fileName = "get_next_line.c";
// 	fd = open(fileName, O_RDWR);
// 	i = 0;
// 	line = "";
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }
