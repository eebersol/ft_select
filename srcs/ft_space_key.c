/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_space_key(t_select *select)
{
	t_env 	*env;
	t_list 	*list;

	if ((size_t)select->x < select->max_len)
	{
		select->index = select->y;
		list = ft_lstget_at(select->env, select->index);
		env = list->content;
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		ft_putendl_fd(env->arg_name, 1);
	}
	else if ((size_t)select->x >= select->max_len)
	{
		select->index = select->y + select->max_li - 1;
		list = ft_lstget_at(select->env, select->index);
		env = list->content;
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		ft_putendl_fd(env->arg_name, 1);
	}
}
