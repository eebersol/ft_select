/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_col_li_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:12:00 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 16:12:01 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

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
	select->max_len = (ft_get_len_max(select->env, select)) + 1;
	select->col = (ft_lstlen(select->env) / select->max_li) + 1;
	select->last_li = ft_lstlen(select->env)
	- ((select->max_li - 1) * (select->col - 1));
}
