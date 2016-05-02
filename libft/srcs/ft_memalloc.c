/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:21:33 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/15 15:07:33 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp_mem;

	tmp_mem = malloc(size);
	if (tmp_mem == NULL)
		return (NULL);
	ft_memset(tmp_mem, 0, size);
	return (tmp_mem);
}
