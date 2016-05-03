/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:25:27 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/29 17:25:28 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_init_select(t_select *select)
{
	select->env = NULL;
	select->x = 0;
	select->y = 0;
	select->col = 0;
	select->li = 0;
	select->max_col = 0;
	select->index = 0;
	select->cur_col = 0;
	select->win_count = 0;
	select->max_len = 0;
	select->first_process = 0;
	select->count_mr = 0;
}