/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 18:17:46 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 15:19:31 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nextlist;

	list = *alst;
	while (list)
	{
		nextlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nextlist;
	}
	*alst = NULL;
}
