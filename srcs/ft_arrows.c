/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_arrow_top(t_select *select)
{
	select->y--;
	if (select->y < 0)
	{
		select->y = select->max_li - 2;
		select->index += (select->max_li - 2);
	}
	else
		select->index--;
}

void	ft_arrow_bot(t_select *select)
{
	select->y++;
	if (select->y > select->max_li - 2)
	{
		select->y = 0;
		select->index -= (select->max_li - 2);
	}
	else if (select->index + 1 == ft_lstlen(select->env))
	{
		select->y = 0;
		select->x = 0;
		select->index = 0;
	}
	else
		select->index++;;
}

void	ft_arrow_left(t_select *select)
{
	select->x -= select->max_len;
	if (select->x < 0)
	{
		select->x = select->max_len * select->col - select->max_len;
		select->index = ((select->max_li - 2) * (select->col + 1)) - (select->last_li) - ((select->max_li - 1) -(select->y + 1));
	}
	else
		select->index -= select->max_li - 1;
	if (select->index >= ft_lstlen(select->env))
		{
			select->index = ft_lstlen(select->env) - 1;
			select->x = select->max_len * select->col - select->max_len;
			select->y = select->last_li - 1;
		}
}

void	ft_arrow_right(t_select *select)
{
		select->x += select->max_len;
		if ((size_t)select->x > select->max_len * select->col - select->max_len)
		{
			select->x = 0;
			select->index = select->y;
		}
		else if ((((size_t)select->x / select->max_len) == (select->col - 1)
		&& ((select->y + 1) > select->last_li)))
		{
			select->x = 0;
			select->index = select->y;
		}
		else
			select->index += select->max_li - 1;
}