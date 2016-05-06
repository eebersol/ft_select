/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalphanumeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:05:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 21:05:24 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isalphanumeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (((ft_isalpha(str[i])) == 1 || str[i] == '_')
			&& ((ft_isalnum(str[i])) == 1 || str[i] == '_'))
			i++;
		else
			return (1);
	}
	return (0);
}
