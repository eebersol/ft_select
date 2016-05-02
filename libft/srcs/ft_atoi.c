/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:19:20 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 15:03:00 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		value;
	int		i;
	int		negative;

	value = 0;
	i = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '\n' ||
			str[i] == '\t' || str[i] == '\v' || str[i] == '\r' ||
			str[i] == '\f')
		i++;
	if ((str[i] == '-' && (str[i + 1] >= '0')) || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] < '0' && str[i] > '9')
		return (0);
	return ((negative) ? -value : value);
}
