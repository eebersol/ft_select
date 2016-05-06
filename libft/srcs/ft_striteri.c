/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:16:40 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/11 20:12:52 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *s))
{
	unsigned int i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s != '\0')
	{
		(*f)(i, s);
		i++;
		s++;
	}
}
