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

void	ft_move_where(t_select *select, char *buffer)
{
	if (LEFT && select->x > 0)
		select->x -= select->max_len;
	else if (TOP && select->y > 0)
		select->y--;
	else if (BOTTOM)
	{
			if ((size_t)select->x >= (((select->col) * select->max_len) - select->max_len) 
				&& (select->y > select->last_li))
				return ;
			else if (select->y < (select->max_li - 2))
				select->y++;
	}
	else if (RIGHT)
	{
		if ((size_t)select->x >= (((select->col) * select->max_len) - select->max_len))
			return ;
		else if ((((select->x / select->max_len) * select->max_len) == (((select->col - 1) * select->max_len) - select->max_len))
			&& ((size_t)select->y > select->last_li + select->col))
			return ;
		else
			select->x += select->max_len;
	}
	else if (SPACE)
		ft_space_key(select);
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
}