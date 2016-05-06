/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 18:55:06 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/12 18:56:21 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst == NULL || *alst == NULL)
		return ;
	list = *alst;
	*alst = list->next;
	del(list->content, list->content_size);
	free(list);
}
