/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:22:37 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:23:08 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	new_word;
	size_t	words;

	i = 0;
	new_word = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && new_word == 0)
		{
			new_word = 1;
			words++;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (words);
}

static size_t	mem_count(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static void	ft_free_all(char **str, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**ft_splitcpy(char const *s, char c, char **str)
{
	size_t	a;
	size_t	i;
	size_t	len_a;
	size_t	word_count;

	i = 0;
	a = 0;
	word_count = ft_word_count(s, c);
	while (a < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		len_a = mem_count(&s[i], c);
		str[a] = malloc(sizeof(char) * (len_a + 1));
		if (!str[a])
		{
			ft_free_all(str, a);
			return (NULL);
		}
		ft_strlcpy(str[a], &s[i], len_a + 1);
		i += len_a;
		a++;
	}
	str[a] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	str = malloc(sizeof(char *) * (word_count + 1));
	if (!str)
		return (NULL);
	return (ft_splitcpy(s, c, str));
}

// int main(void)
// {
// 	char const *s = "hello! dsaldas asdkm test for split";
// 	char c = ' ';
// 	size_t word_count = ft_word_count(s, c);
// 	char **result = ft_split(s, c);

// 	for (int i = 0; result[i] != NULL; i++)
// 		printf("%s\n", result[i]);
// 	ft_free_all(result, word_count);
// }