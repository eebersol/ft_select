/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:51:29 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 20:24:40 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)malloc(sizeof(*str) * len);
	ft_memcpy(str, src, len);
	ft_memcpy(dst, str, len);
	free(str);
	return (dst);
}
