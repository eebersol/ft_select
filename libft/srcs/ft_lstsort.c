/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:43:08 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/21 11:43:11 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_insertion_sort(t_list **list,
						int (*f)(t_list *list_a, t_list *list_b))
{
	t_list	*sorted;
	t_list	*current;
	t_list	*next;

	sorted = NULL;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		ft_sorted_insert(&sorted, current, f);
		current = next;
	}
	*list = sorted;
}

void	ft_sorted_insert(t_list **list, t_list *new_elem,
						int (*f)(t_list *list_a, t_list *list_b))
{
	t_list	*current;

	if (*list == NULL || !f(*list, new_elem))
	{
		new_elem->next = *list;
		*list = new_elem;
	}
	else
	{
		current = *list;
		while (current->next != NULL &&
			f(current->next, new_elem))
		{
			current = current->next;
		}
		new_elem->next = current->next;
		current->next = new_elem;
	}
}
