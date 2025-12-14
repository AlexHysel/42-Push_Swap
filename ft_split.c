/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin afomin@student.42kl.edu.my          #+#  +:+        #+#       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:05:28 by afomin            #+#    #+#             */
/*   Updated: 2025/12/14 19:19:56 by afomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char	*ft_strdup(const char *str)
{
	unsigned int		i;
	char				*duplicate;

	duplicate = malloc(len((char *)str) + 1);
	if (duplicate != NULL)
	{
		i = -1;
		while (str[++i])
			duplicate[i] = str[i];
		duplicate[i] = '\0';
	}
	return (duplicate);
}

static char	*ft_substr(char const *s, unsigned int start, unsigned int l)
{
	char			*substr;
	int				s_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	s_len = len((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + l > s_len)
		l = s_len - start;
	substr = malloc(l + 1);
	if (substr)
	{
		i = -1;
		while (++i < l && s[start + i])
			substr[i] = s[start + i];
		substr[i] = '\0';
	}
	return (substr);
}

unsigned int	ft_count_words(char const *s)
{
	unsigned int	count;
	char			in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	element;
	char			**pointers;

	pointers = malloc((ft_count_words(s) + 1) * sizeof(char *));
	if (pointers == NULL)
		return (NULL);
	i = 0;
	start = 0;
	element = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		start = i;
		while (s[i] && s[i] != ' ')
			i++;
		if (i > start)
			pointers[element++] = ft_substr(s, start, i - start);
	}
	pointers[element] = NULL;
	return (pointers);
}
