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

void	ft_printf(t_select *select)
{
	printf("select->x = %dp\n", select->x);
	printf("select->y = %dp\n", select->y);
	printf("select->col = %zup\n", select->col);
	printf("select->max_li = %dp\n", select->max_li);
	printf("select->max_col = %zup\n", select->max_col);
	printf("select->index = %dp\n", select->index);
	printf("select->cur_col = %dp\n", select->cur_col);
	printf("select->win_count = %dp\n", select->win_count);
	printf("select->max_len = %zup\n", select->max_len);
	printf("select->first_process = %d\n", select->first_process);
	printf("select->count_mr = %dp\n", select->count_mr);
}