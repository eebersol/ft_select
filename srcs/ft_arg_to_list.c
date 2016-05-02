/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 19:35:35 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/28 19:35:36 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_lstlen(t_list *list)
{
	int		i;
	t_env	*env;

	i = 0;
	while (list)
	{
		env = list->content;
		i++;
		list = list->next;
	}
	return (i);
}

void	ft_arg_to_list(t_list **list, char **av)
{
	t_env	env;
	int		i;

	i = 1;
	while (av[i])
	{
		env.arg_name = ft_strdup(av[i]);
		ft_lstadd(list, ft_lstnew(&env, sizeof(t_env)));
		i++;
	}
	if (list)
		ft_lstrev(list);
}
