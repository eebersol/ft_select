/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_first_sharp(t_select *select)
{
	t_list *cur;
	t_env *env;

	if (select->x == 0 && select->y == 0)
	{
		cur = select->env;
		env = cur->content;
		cur = ft_lstget_at(cur, select->index );
		env = cur->content;
		env->is_us = 1;
	}
}

void 	ft_check_selected(t_select *select)
{
	t_env	*env;
	t_list	*cur;


	cur = select->env;
	cur = ft_lstget_at(cur, select->index);
	env = cur->content;
	if (env->is_mr == 1)
	{
		cur = select->env;
		cur = ft_lstget_at(cur, select->index + 1);
		env = cur->content;
		if (env->is_mr == 1)
			env->is_mr = 1;
		else
			env->is_mr = 0;
	}
}

void	ft_done_value(t_select *select)
{
	t_env *env;
	t_list *cur;

	cur = select->env;
	if (select->index >= 0 && select->index != ft_lstlen(select->env))
	{
		cur = ft_lstget_at(cur, select->index);
		env = cur->content;
		env->is_us = 1;
		cur = ft_lstget_at(cur, select->index + 1);
		cur = select->env;
		env = cur->content;
		env->is_us = 0;
	}
	else if (select->index == ft_lstlen(select->env))
	{
		cur = ft_lstget_at(cur, select->index - 1);
		env = cur->content;
		env->is_us = 1;
		cur = select->env;
		env = cur->content;
		env->is_us = 0;
	}
	else
	{
		cur = ft_lstget_at(cur, 0);
		env =	cur->content;
		env->is_us = 1;
	}
}

static void	ft_free_node(void *content, size_t size)
{
	t_env	*env;

	(void)size;
	env = content;
	if (!content)
		return ;
	if (env->arg_name)
		ft_strdel(&(env->arg_name));
	free(env);
}

void	ft_delete_key(t_select *select)
{
	if (ft_lstlen(select->env) - 1 != 0)
	{
		select->deletes = 1;
		ft_check_selected(select);
		ft_lstdel_at(&select->env, select->index, &ft_free_node);
		if (select->y == 0 && select->x > 0 && select->index == ft_lstlen(select->env))
		{
			select->xdelete = select->x - select->max_len;
			select->ydelete = select->max_li - 2;
			select->indexdelete = select->index - 1;
		}
		else if (select->y == 0 && select->x == 0)
		{
				select->ydelete  = 0;
				select->xdelete = 0;
				select->indexdelete = select->index;
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
		ft_done_value(select);
		select->y = 0;
		select->x = 0;
		ft_list_show(select->env);
	}
	else
		exit(1);
}