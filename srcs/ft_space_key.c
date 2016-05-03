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

void  	ft_save_select(t_select *select)
{
	t_list *list;
	t_env 	*env;
	int 	i;
	
	i = 0;
	list = select->env;
	env = list->content;
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgetstr("ho", NULL), 0, tputs_putchar);
	while (list)
	{
		env = list->content;
		if (env->is_mr == 1)
		{
			tputs(tgetstr("me", NULL), 0, tputs_putchar);
			ft_putstr(env->arg_name);
			i++;
			if (i < select->count_mr)
				ft_putstr(", ");
			else if (i == select->count_mr)
				ft_putchar('\n');
		}
		list = list->next;
	}
	exit (0);
}

void	ft_select_unselect(t_select *select)
{
	t_env 	*env;
	t_list 	*list;

	list = select->env;
	list = ft_lstget_at(select->env, select->index);
	env = list->content;
	if (env->is_mr == 0)
	{
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
		select->count_mr++;
		env->is_mr = 1;
		ft_putendl_fd(env->arg_name, 1);
	}
	else
	{
		tputs(tgetstr("me", NULL), 0, tputs_putchar);
		env->is_mr = 0;
		select->count_mr--;
		ft_putendl_fd(env->arg_name, 1);
	}
}

void	ft_space_key(t_select *select)
{
	if ((size_t)select->x < select->max_len)
		select->index = select->y;
	else if ((size_t)select->x >= select->max_len)
	{
		select->index = select->y + ((select->x / select->max_len) * select->max_li)
		- (1 * (select->x / select->max_len));
	}
	ft_select_unselect(select);
}
