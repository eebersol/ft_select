/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:40:19 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 14:44:46 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *var_dst;
	unsigned char *var_src;

	if (n == 0 || src == dst)
		return (dst);
	var_dst = (unsigned char *)dst;
	var_src = (unsigned char *)src;
	while (--n)
	{
		*var_dst = *var_src;
		var_dst++;
		var_src++;
	}
	*var_dst = *var_src;
	return (dst);
}
