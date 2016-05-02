/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:07:27 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 19:15:07 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_len_int(int nbr)
{
	int nbr_len;

	if (nbr == 0)
		return (1);
	nbr_len = 0;
	while (nbr != 0)
	{
		nbr_len++;
		nbr = nbr / 10;
	}
	return (nbr_len);
}
