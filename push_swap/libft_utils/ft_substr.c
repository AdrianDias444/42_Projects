#include "../header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	char const		*s;
// 	unsigned int	start;
// 	size_t			len;

// 	if(argc == 4)
// 	{
// 		s = argv[1];
// 		start = (unsigned int)ft_atoi(argv[2]);
// 		len = (size_t)ft_atoi(argv[3]);
// 		printf("%s", ft_substr(s, start, len));
// 	}
// }