/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:49:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/30 19:49:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_select.h>

void	ft_init_window(t_select *select)
{
	if (ioctl(0, TIOCGWINSZ, &select->win) != -1)
	{
		select->win_count++;
		//ft_printf(select);
		select->x = 0;
		select->y = 0;
		ft_list_show(select->env);
	}
}