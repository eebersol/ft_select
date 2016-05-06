/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:19:17 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/12 14:32:18 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i == 0 || n == 0)
		return (1);
	else
		return (0);
}
