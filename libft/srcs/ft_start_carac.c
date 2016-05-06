/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:24:42 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 15:39:00 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_start_carac(char const *str, int i, int len)
{
	while ((str[i] != '\0') && i < len && (str[i] == ' ' || str[i] == '\n'
				|| str[i] == '\t'))
		i++;
	return ((char *)&str[i]);
}
