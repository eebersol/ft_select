/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:46:57 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 14:45:46 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*var_dst;
	unsigned char	*var_src;

	var_dst = (unsigned char *)dst;
	var_src = (unsigned char *)src;
	while (n--)
	{
		*var_dst = *var_src;
		if (*var_src == (unsigned char)c)
			return ((void *)(var_dst + 1));
		var_dst++;
		var_src++;
	}
	return (NULL);
}
