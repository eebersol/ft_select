/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:12:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 16:12:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			ft_check_is_mr(t_select *select, t_env *env)
{
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	if (select->indexdelete + select->cur_col == select->index)
	{
		if (env->is_us == 1)
			tputs(tgetstr("us", NULL), 0, tputs_putchar);
		env->is_us = 0;
	}
}

void			ft_check_status(t_select *select, t_env *env)
{
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	if (env->is_mr == 1)
	{
		ft_check_is_mr(select, env);
	}
	else if (env->is_us == 1 && env->is_mr == 0)
	{
		tputs(tgetstr("me", NULL), 0, tputs_putchar);
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		env->is_us = 0;
	}
	else if (select->first_process == 0)
	{
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		if (env->is_mr == 1)
			tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		select->first_process = 1;
		select->first_us_delete = 1;
	}
	else
		tputs(tgetstr("me", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, select->tty);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("ue", NULL), 0, tputs_putchar);
}

void			ft_put_here(t_select *select, t_env *env)
{
	ft_get_col_li(select);
	if (select->y < select->max_li - 1)
	{
		ft_check_status(select, env);
		select->y++;
		select->index++;
		if (select->first_us_delete == 1)
			tputs(tgetstr("ue", NULL), 0, tputs_putchar);
	}
	else
	{
		select->cur_col++;
		select->y = 0;
		select->x += select->max_len;
		select->index++;
		ft_put_here(select, env);
	}
}

void	static	ft_new_pos(t_select *select)
{
	select->x = select->xdelete;
	select->y = select->ydelete;
	select->index = select->indexdelete;
	select->deletes = 0;
}

void			ft_list_show(t_list *list)
{
	t_env		*env;
	t_list		*cur;
	t_select	*select;

	cur = list;
	select = ft_struct_select();
	select->index = 0;
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	while (cur)
	{
		env = cur->content;
		if (env->arg_name != NULL)
			ft_put_here(select, env);
		cur = cur->next;
	}
	if (select->deletes >= 1)
		ft_new_pos(select);
	else
	{
		select->x = 0;
		select->y = 0;
		select->index = 0;
	}
}
