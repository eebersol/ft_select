/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:13:28 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 14:49:46 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*var_s1;
	unsigned char	*var_s2;
	int				i;

	if (!s1 && !s2 && !n)
		return (0);
	i = 0;
	var_s1 = (unsigned char *)s1;
	var_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (var_s1[i] != var_s2[i])
			return (var_s1[i] - var_s2[i]);
		i++;
	}
	return (0);
}
