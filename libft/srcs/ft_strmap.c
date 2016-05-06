/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:25:19 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 15:11:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(*result) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
