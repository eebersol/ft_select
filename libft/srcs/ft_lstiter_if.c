/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 19:45:59 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/13 15:20:00 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter_if(t_list *lst, void (*f)(t_list *elem),
					int (*g)(t_list *elem))
{
	while (lst)
	{
		if (g(lst) == 1)
			f(lst);
		lst = lst->next;
	}
}
