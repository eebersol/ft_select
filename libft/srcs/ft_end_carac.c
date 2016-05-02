/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_carac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:20:44 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 16:15:11 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_end_carac(char const *str, int len)
{
	if (str == NULL)
		return (NULL);
	while ((str[len - 1] != '\0') && len > 0 && (str[len - 1] == ' '
				|| str[len - 1] == '\n' || str[len - 1] == '\t'))
		len--;
	return ((char *)&str[len]);
}
