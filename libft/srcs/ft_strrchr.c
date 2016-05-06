/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:36:44 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 15:00:54 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*var_s;

	var_s = (const char *)s;
	var_s = var_s + ft_strlen(s);
	while (*var_s != (char)c && var_s != s)
		var_s--;
	if (*var_s == (char)c)
		return ((char *)var_s);
	return (NULL);
}
