/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 20:03:00 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/12 20:04:54 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	if (!current)
	{
		ft_lstadd(alst, new);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}
