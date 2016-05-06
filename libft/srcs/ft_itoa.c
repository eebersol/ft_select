/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:25:16 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 20:05:35 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(int n)
{
	int		nbr_len;
	int		value;
	char	*result;

	value = ft_sign_int(n);
	nbr_len = ft_len_int(n);
	result = NULL;
	result = (char*)malloc(sizeof(char) * (nbr_len + value + 1));
	if (result)
	{
		result = result + nbr_len + value;
		*result = '\0';
		if (!n)
			*--result = '0';
		while (n != 0)
		{
			*--result = ft_positive(n % 10) + '0';
			n = n / 10;
		}
		if (value)
			*--result = '-';
	}
	return (result);
}
