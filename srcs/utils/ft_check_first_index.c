/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 22:27:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/28 22:27:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_check_first_index(t_select *select)
{
	t_env *env;
	t_list *cur;

	cur = select->env;
	cur = ft_lstget_at(cur, 0);
	env = cur->content;
	if (env->is_mr == 1)
	{
			cur = ft_lstget_at(cur, 1);
			env = cur->content;
			if (env->is_mr == 0)
			{
				cur = ft_lstget_at(cur, 0);
				env = cur->content;
				env->is_mr = 0;
			}
	}
}