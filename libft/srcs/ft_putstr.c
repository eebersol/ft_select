/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:18:21 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 15:57:49 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
