/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:30:08 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 18:50:31 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_chartrim(char *str, char c)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str);
	i = 0;
	if (str == NULL)
		return (NULL);
	while ((str[len - 1] != '\0') && len >= 0 && (str[len - 1] == (char)c))
		len--;
	while ((str[i] != '\0') && i < len && (str[i] == (char)c))
		i++;
	if (!(result = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	j = 0;
	while (i < len)
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
