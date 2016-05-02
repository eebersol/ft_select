/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_to_tlb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 21:59:53 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/11 21:59:57 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(const char *s)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t') &&
			s[i] != ' ' && s[i] != '\t')
			words++;
		i++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

char			**ft_word_to_tbl(char const *s)
{
	char	**word_tbl;
	size_t	nb_words;
	size_t	word_len;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	nb_words = ft_count_words(s);
	word_tbl = (char **)malloc(sizeof(char *) * (nb_words + 1));
	while (n < nb_words && word_tbl)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		word_len = ft_wordlen(&s[i]);
		word_tbl[n] = malloc(sizeof(**word_tbl) * (word_len + 1));
		ft_strncpy(word_tbl[n], &s[i], word_len);
		word_tbl[n][word_len] = '\0';
		while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
			i++;
		n++;
	}
	word_tbl[n] = NULL;
	return (word_tbl);
}
