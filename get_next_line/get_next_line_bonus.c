#include "get_next_line_bonus.h"

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
	static char	*stack[FD_MAX];
	char		*line;
	char		*temp;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stack[fd]), NULL);

	temp = read_newline(fd, stack[fd]);
	if (!temp || !*temp)
		return (free(stack[fd]), stack[fd] = NULL, NULL);
	
    stack[fd] = temp;
	line = extract_line(stack[fd]);
	if (!line)
		return (free(stack[fd]), stack[fd] = NULL, NULL);

	stack[fd] = clean_old_stack(stack[fd]);
	if (stack[fd] && !*stack[fd])
	{
		free(stack[fd]);
		stack[fd] = NULL;
	}
	return (line);
}
// int main(void)
// {
// 	int fd = open("get_next_line.c", O_RDWR);
//     int fd2 = open("get_next_line_bonus.c", O_RDWR);

// 	int i = 0;
// 	char *line="";
//     char *line2="";

// 	while (line && line2)
// 	{
// 		line = get_next_line(fd);
//         line2 = get_next_line(fd2);
// 		printf("%s", line);
//         printf("%s", line2);
// 		free(line);
//         free(line2);
// 		i++;
// 	}
// }
