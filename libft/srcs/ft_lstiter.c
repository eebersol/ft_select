/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:45:59 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 15:20:00 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nextlist;

	while (lst)
	{
		nextlist = lst->next;
		f(lst);
		lst = nextlist;
	}
}
