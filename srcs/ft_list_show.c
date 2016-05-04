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

void ft_check_status(t_select *select, t_env *env)
{
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
	if (env->is_mr == 1)
	{
		tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	}
	else if (env->is_us == 1)
		tputs(tgetstr("us", NULL), 0, tputs_putchar);
	else
		tputs(tgetstr("me", NULL), 0, tputs_putchar);
	ft_putendl_fd(env->arg_name, 0);
}

void	ft_get_col_li(t_select *select)
{
	if (select->win_count == 0)
	{
		select->max_col = tgetnum("co");
		select->max_li = tgetnum("li");
	}
	else if (select->win_count != 0)
	{
		select->max_col = select->win.ws_col;
		select->max_li = select->win.ws_row;
	}
	select->max_len = ft_get_len_max(select->env) + 1;
	select->col = (ft_lstlen(select->env) / select->max_li) + 1;
	select->last_li =  ft_lstlen(select->env) - ((select->max_li - 1) * (select->col - 1));
}

void	ft_put_here(t_select *select, t_env *env)
{
	ft_get_col_li(select);
	if (select->y < select->max_li - 1)
	{
		ft_check_status(select, env);
		//ft_putendl_fd(env->arg_name, 1);
		select->y++;
		select->index++;
	}
	else
	{
		select->cur_col++;
		select->y = 0;
		select->x += select->max_len;
		select->index++;
		ft_put_here(select, env);
	}
//	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
}

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_list_show(t_list *list)
{
	t_env	*env;
	t_list	*cur;
	t_select	*select;

	cur = list;
	select = ft_struct_select();
	tputs(tgetstr("cl", NULL), 0, tputs_putchar); // clean entire screen
	tputs(tgetstr("ho", NULL), 0, tputs_putchar); // Home position
	while (cur)
	{
		env = cur->content;
	//	tputs(tgetstr("cr", NULL), 0, tputs_putchar); //move the cursor to the beginning of the line
		if (env->arg_name != NULL)
			ft_put_here(select, env);
		cur = cur->next;
	}
	select->cur_col = 0;
	select->x = 0;
	select->y = 0;
	select->index = 0;
	tputs(tgetstr("ho", NULL), 0, tputs_putchar); 
}