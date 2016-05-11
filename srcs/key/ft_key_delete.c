/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static	void	ft_check_selected_bis(t_select *select, t_list *cur,
										t_env *env)
{
	cur = select->env;
	cur = ft_lstget_at(cur, 1);
	env = cur->content;
	env->is_us = 1;
	cur = cur->next;
	env->is_us = 0;
	select->first_us_delete = 1;
}

static	void	ft_save_pos(t_select *select)
{
	if (select->y == 0 && select->x > 0
		&& select->index == ft_lstlen(select->env))
	{
		select->xdelete = select->x - select->max_len;
		select->ydelete = select->max_li - 2;
		select->indexdelete = select->index - 1;
	}
	else if (select->y == 0 && select->x == 0)
	{
		select->indexdelete = 0;
		select->first_us_delete = 0;
	}
	else if (select->index == ft_lstlen(select->env))
	{
		select->xdelete = select->x;
		select->ydelete = select->y - 1;
		select->indexdelete = select->index - 1;
	}
	else
	{
		select->xdelete = select->x;
		select->ydelete = select->y;
		select->indexdelete = select->index;
	}
}

static	void	ft_check_selected(t_select *select)
{
	t_env	*env;
	t_list	*cur;

	if (select->index < ft_lstlen(select->env))
	{
		cur = select->env;
		cur = ft_lstget_at(cur, select->index);
		env = cur->content;
		if (env->is_mr == 1)
		{
			if (select->index + 1 != ft_lstlen(select->env))
			{
				cur = cur->next;
				env = cur->content;
				if (env->is_mr == 1)
					env->is_mr = 1;
				else
					env->is_mr = 0;
			}
		}
		if (select->index == 0 && env->is_us == 0 && select->deletes == 2
			&& ft_lstlen(select->env) > 2)
			ft_check_selected_bis(select, cur, env);
	}
}

static	void	ft_done_value(t_select *select)
{
	t_env	*env;
	t_list	*cur;

	cur = select->env;
	if (select->index > 0 && select->index != ft_lstlen(select->env))
	{
		cur = ft_lstget_at(cur, select->index);
		env = cur->content;
		env->is_us = 1;
	}
	else if (select->index == ft_lstlen(select->env))
	{
		cur = ft_lstget_at(cur, select->index - 1);
		env = cur->content;
		env->is_us = 1;
	}
	else
	{
		cur = ft_lstget_at(cur, 0);
		env = cur->content;
		env->is_us = 1;
	}
}

void			ft_delete_key(t_select *select)
{
	if (ft_lstlen(select->env) - 1 != 0)
	{
		select->deletes = 1;
		ft_check_selected(select);
		select->deletes = 2;
		ft_lstdel_at(&select->env, select->index, &ft_free_node);
		ft_check_selected(select);
		ft_save_pos(select);
		ft_done_value(select);
		select->cur_col = 0;
		select->y = 0;
		select->x = 0;
		tputs(tgetstr("ue", NULL), 0, tputs_putchar);
		ft_list_show(select->env);
	}
	else
	{
		ft_select_reset(ft_struct_select());
		exit(1);
	}
}
