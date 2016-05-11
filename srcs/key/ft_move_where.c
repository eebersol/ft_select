/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_where.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:15:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/30 19:15:37 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_ue_node(t_select *select)
{
	t_env	*env;
	t_list	*list;

	list = ft_lstget_at(select->env, select->index);
	if (list)
	{
		env = list->content;
		tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
		if (env->is_mr == 1)
		{
			tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		}
		else
			tputs(tgetstr("me", NULL), 0, tputs_putchar);
		tputs(tgetstr("ue", NULL), 0, tputs_putchar);
		ft_putendl_fd(env->arg_name, select->tty);
	}
	else
		return ;
}

void	ft_us_node(t_select *select)
{
	t_env	*env;
	t_list	*list;

	list = ft_lstget_at(select->env, select->index);
	if (list)
	{
		env = list->content;
		tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		if (env->is_mr == 1)
		{
			tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		}
		else if (env->is_mr == 0)
			tputs(tgetstr("se", NULL), 0, tputs_putchar);
		ft_putendl_fd(env->arg_name, select->tty);
	}
	else
		return ;
}

void	ft_move_where(t_select *select, char *b)
{
	t_env	*env;
	t_list	*list;

	if (select->index < 0 || select->index >= ft_lstlen(select->env))
	{
		select->x = 0;
		select->y = 0;
		select->index = 0;
	}
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	ft_ue_node(select);
	if (LEFT)
		ft_arrow_left(select);
	else if (TOP)
		ft_arrow_top(select);
	else if (BOTTOM)
		ft_arrow_bot(select);
	else if (RIGHT)
		ft_arrow_right(select);
	if (select->index < 0 || select->index >= ft_lstlen(select->env))
	{
		select->x = 0;
		select->y = 0;
		select->index = 0;
	}
	ft_us_node(select);
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
}
