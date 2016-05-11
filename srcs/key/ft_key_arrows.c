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
	if (select->y < 0 && select->x == 0)
	{
		select->y = select->last_li - 1;
		select->x = select->max_len * (1 + select->col - 2);
		select->index += ft_lstlen(select->env) - 1;
	}
	else if (select->y < 0)
	{
		select->y = select->max_li - 2;
		select->x -= select->max_len;
		select->index--;
	}
	else if (select->deletes == 0)
		select->index--;
	if (select->index < 0)
		select->index = 0;
}

void	ft_arrow_bot(t_select *select)
{
	select->y++;
	if (select->index + 1 == ft_lstlen(select->env))
	{
		select->y = 0;
		select->x = 0;
		select->index = 0;
	}
	else if (select->y > select->max_li - 2)
	{
		select->y = 0;
		select->x += select->max_len;
		select->index++;
	}
	else
		select->index++;
	if (select->index < 0)
		select->index = 0;
}

void	ft_arrow_left(t_select *select)
{
	select->x -= select->max_len;
	if (select->x < 0)
	{
		select->x = select->max_len * select->col - select->max_len;
		select->index = ((select->max_li - 2) * (select->col + 1))
		- (select->last_li) - ((select->max_li - 1) - (select->y + 1));
		select->index += 2;
	}
	else
		select->index -= select->max_li - 1;
	if (select->index >= ft_lstlen(select->env))
	{
		select->index = ft_lstlen(select->env) - 1;
		select->x = select->max_len * select->col - select->max_len;
		select->y = select->last_li - 1;
	}
	if (select->index < 0)
		select->index = 0;
}

void	ft_arrow_right(t_select *select)
{
	select->x += select->max_len;
	if (select->x > select->max_len * select->col - select->max_len)
	{
		select->x = 0;
		select->index = select->y;
	}
	else if (((select->x / select->max_len) == (select->col - 1)
	&& ((select->y + 1) > select->last_li)))
	{
		select->x = 0;
		select->index = select->y;
	}
	else
		select->index += select->max_li - 1;
	if (select->index < 0)
		select->index = 0;
}
