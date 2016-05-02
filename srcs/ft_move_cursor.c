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

/*static void ft_move_left(t_select *select)
{
	while ((size_t)select->x > select->max_len)
		select->x--;
}
static void	ft_move_right(t_select *select)
{
	if (select->cur_col == 0)
	{
		select->x += select->max_len;
		select->cur_col++;
	}
	while ((size_t)select->x % select->max_len != 0)
		select->x += select->max_len;
	
}*/

void	ft_move_where(t_select *select, char *buffer)
{
	if (LEFT)
	{
		select->x -= select->max_len;
	}
	else if (TOP)
		select->y--;
	else if (BOTTOM)
		select->y++;
	else if (RIGHT)
		select->x += select->max_len;
	else if (SPACE)
		ft_space_key(select);
	tputs(tgoto((tgetstr("cm", NULL)), select->x, select->y), 0, tputs_putchar);
}