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

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_lidos = 1;
	while (!ft_strchr(stack, 10) && bytes_lidos > 0)
	{
		bytes_lidos = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lidos <= 0)
			break ;
		buffer[bytes_lidos] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*extract_line(char *stack)
{
	int	i;

	if (!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	return (ft_substr(stack, 0, i));
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
    if(stack[i] == '\n')
        i++;
    if (!stack[i])
		return (free(stack), NULL);
	new_stack = ft_substr(stack, i, ft_strlen(stack) - 1);
	free(stack);
	return (new_stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*temp;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stack), NULL);

	temp = read_newline(fd, stack);
	if (!temp || !*temp)
		return (free(stack), stack = NULL, NULL);
	
    stack = temp;
	line = extract_line(stack);
	if (!line)
		return (free(stack), stack = NULL, NULL);

	stack = clean_old_stack(stack);
	if (stack && !*stack)
	{
		free(stack);
		stack = NULL;
	}
	return (line);
}
// int main(void)
// {
// 	char* fileName = "get_next_line.c";

// 	int fd = open(fileName, O_RDWR);
// 	int i = 0;
// 	char *line="";

// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }
