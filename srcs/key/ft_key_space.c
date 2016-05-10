/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_unselect(t_select *select, t_env *env, t_list *list)
{
	tputs(tgetstr("se", NULL), 0, tputs_putchar);
	tputs(tgetstr("us", NULL), 0, tputs_putchar);
	env->is_mr = 0;
	select->count_mr--;
	tputs(tgetstr("ue", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, select->tty);
	ft_arrow_bot(select);
	tputs(tgoto((tgetstr("cm", NULL)),
		select->x, select->y), 0, tputs_putchar);
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	if (env->is_mr == 1)
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	tputs(tgetstr("us", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, select->tty);

}

static void	ft_select(t_select *select, t_env *env, t_list *list)
{
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	tputs(tgetstr("ue", NULL), 0, tputs_putchar);
	select->count_mr++;
	env->is_mr = 1;
	ft_putendl_fd(env->arg_name, select->tty);
	tputs(tgetstr("se", NULL), 0, tputs_putchar);
	ft_arrow_bot(select);
	tputs(tgoto((tgetstr("cm", NULL)),
		select->x, select->y), 0, tputs_putchar);
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	tputs(tgetstr("us", NULL), 0, tputs_putchar);
	if (env->is_mr == 1)
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, select->tty);
}

static void	ft_select_unselect(t_select *select)
{
	t_env	*env;
	t_list	*list;

	list = select->env;
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	if (env->is_mr == 0)
		ft_select(select, env, list);
	else
		ft_unselect(select, env, list);
}

void		ft_space_key(t_select *select)
{
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	ft_select_unselect(select);
}
