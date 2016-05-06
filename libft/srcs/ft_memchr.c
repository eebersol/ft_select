/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:56:42 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 14:52:30 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*var_s;
	unsigned char	cast_c;
	size_t			i;

	i = 0;
	cast_c = (unsigned char)c;
	var_s = (unsigned char *)s;
	while (i < n)
	{
		if (var_s[i] == cast_c)
			return (var_s + i);
		i++;
	}
	return (NULL);
}
