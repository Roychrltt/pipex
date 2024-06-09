/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roychrltt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:21:59 by roychrltt         #+#    #+#             */
/*   Updated: 2024/06/09 12:27:22 by roychrltt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static void	split_into_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < (unsigned int)count_word(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			result[j][k++] = s[i++];
		}
		result[j][k] = 0;
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	size_t	word_len;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	res = malloc((word_count + 1) * sizeof (char *));
	if (!res)
		return (NULL);
	i = 0;
	word_len = ft_strlen(s) + 1;
	while (i < word_count)
	{
		res[i] = malloc(word_len);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = 0;
	if (word_count)
		split_into_words(res, s, c);
	return (res);
}
