/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:08:27 by eebersol          #+#    #+#             */
/*   Updated: 2016/02/28 18:06:27 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = ((char *)malloc(sizeof(*result) * (len + 1)));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
