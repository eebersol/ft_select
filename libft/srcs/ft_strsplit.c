/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:55:51 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 20:06:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		i;

	i = 0;
	nb_word = ft_part_nbr((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_part_nbr((const char *)s, c) + 1));
	if (t == NULL || s == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_strsub((const char *)s, 0, ft_strlenchar((const char *)s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + ft_strlenchar(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
