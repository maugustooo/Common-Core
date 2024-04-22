/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:23:48 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/19 15:12:50 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*write_word(char *word, char const *str, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = str[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

char	**split_words(char const *str, char c, char **strings, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			word_len++;
		}
		strings[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!strings)
			return (free_array(strings, word));
		write_word(strings[word], str, i, word_len);
		word_len = 0;
		word++;
	}
	strings[word] = 0;
	return (strings);
}

char	**ft_split(char const *str, char c)
{
	char			**strings;
	unsigned int	num_words;

	if (!str)
		return (0);
	num_words = count_words(str, c);
	strings = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!strings)
		return (0);
	strings = split_words(str, c, strings, num_words);
	return (strings);
}
