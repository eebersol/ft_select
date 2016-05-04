/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
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
	t_env *env;
	t_list *list;

	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	tputs(tgetstr("ue", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, 1);
}

void	ft_us_node(t_select *select)
{
	t_env *env;
	t_list *list;

	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	tputs(tgetstr("us", NULL), 0, tputs_putchar);
	if (env->is_mr == 1)
	{
		tputs(tgetstr("so", NULL), 0, tputs_putchar);
	}
	ft_putendl_fd(env->arg_name, 1);
	if (env->is_mr == 0)
		tputs(tgetstr("se", NULL), 0, tputs_putchar);
}

void	ft_move_where(t_select *select, char *buffer)
{
	t_env *env;
	t_list *list;

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
	else if (SPACE)
		ft_space_key(select);
	ft_us_node(select);
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
}