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

void	ft_select_unselect(t_select *select)
{
	t_env 	*env;
	t_list 	*list;

	list = select->env;
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	if (env->is_mr == 0)
	{
		/*if (select->y == select->max_li - 1)
		{
			select->x +=select->max_len;
			select->y = 0;
			tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
		}
		else if ((size_t)select->x >= (((select->col) * select->max_len) - select->max_len) 
			&& (select->y > select->last_li + 1))
				return ;*/
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		tputs(tgetstr("ue", NULL), 0, tputs_putchar);
		select->count_mr++;
		env->is_mr = 1;
		ft_putendl_fd(env->arg_name, select->tty);
		tputs(tgetstr("se", NULL), 0, tputs_putchar);
		ft_arrow_bot(select);
		tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
		list = ft_lstget_at(select->env, select->index);
		env = list->content;
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		ft_putendl_fd(env->arg_name, select->tty);
	}
	else
	{
		tputs(tgetstr("se", NULL), 0, tputs_putchar);
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		env->is_mr = 0;
		select->count_mr--;
		ft_putendl_fd(env->arg_name, select->tty);
	}
}

void	ft_space_key(t_select *select)
{
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	ft_select_unselect(select);
}
