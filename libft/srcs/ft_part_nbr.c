/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:59:55 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 18:43:54 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_part_nbr(const char *s, char c)
{
	int nbr;
	int part;

	nbr = 0;
	part = 0;
	while (*s != '\0')
	{
		if (part == 1 && *s == c)
			part = 0;
		if (part == 0 && *s != c)
		{
			part = 1;
			nbr++;
		}
		s++;
	}
	return (nbr);
}
