/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:27:27 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/07 17:27:48 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstrev(t_list **list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}
