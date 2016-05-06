/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:01:09 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 18:49:43 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[len - 1] != '\0') && len >= 0 && (s[len - 1] == ' '
			|| s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	while ((s[i] != '\0') && i < len && (s[i] == ' ' || s[i] == '\n'
			|| s[i] == '\t'))
		i++;
	if (!(result = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	j = 0;
	while (i < len)
	{
		result[j++] = s[i++];
	}
	result[j] = '\0';
	return (result);
}
