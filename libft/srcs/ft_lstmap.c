/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:55:29 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 15:58:03 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *f_elem;
	t_list *basic_elem;

	new_lst = NULL;
	if (lst && (*f))
	{
		new_lst = (*f)(lst);
		basic_elem = new_lst;
		lst = lst->next;
		while (lst)
		{
			f_elem = (*f)(lst);
			basic_elem->next = f_elem;
			basic_elem = f_elem;
			lst = lst->next;
		}
		basic_elem->next = NULL;
	}
	return (new_lst);
}
