/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:24:30 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 16:05:48 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	long long int	t;

	t = size;
	s = (char *)malloc(sizeof(char) * (t + 1));
	if (s == NULL)
		return (NULL);
	ft_bzero(s, t + 1);
	return (s);
}
