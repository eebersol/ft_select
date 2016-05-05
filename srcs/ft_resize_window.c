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

int 	ft_check_firstwindow(t_select *select)
{
	ft_get_col_li(select);
	if ((size_t)ft_lstlen(select->env) - 1 >= ((select->max_li - 1) * select->col) || ((select->max_col) <  select->col * select->max_len))
	{
		ft_first_display(select);
		return (1);
	}
	else
		return (0);
}

void	ft_first_display(t_select *select)
{
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgoto(NULL, (select->col / 2), (select->max_li/ 2)), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putendl_fd("\n\n[Window to small, please resize	. . . ]", 2);
	ft_putstr("\n	 [ Required Lines -> ");
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr(ft_lstlen(select->env) / select->col);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" , Raws -> ");
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr(select->col);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" --- Current Lines -> ");
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr((select->max_li - 1) * (select->col) / select->col);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" , Raws -> ");
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr(select->max_col / select->max_len);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" ]");
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
}

void	ft_display_winsizetosmall(t_select *select)
{
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgoto(NULL, (select->win.ws_row / 2), (select->win.ws_col / 2)), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putendl_fd("\n\n[Window to small, please resize	. . . ]", 2);
	ft_putstr("\n	 [ Required Line : ");
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr(ft_lstlen(select->env) / select->col);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" --- Current Line : ");
	tputs(tgetstr("mr", NULL), 0, tputs_putchar);
	ft_putnbr((((select->win.ws_row - 1) * (select->win.ws_col / select->max_len))) / select->col);
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
	tputs(tgetstr("md", NULL), 0, tputs_putchar);
	ft_putstr(" ]");
	tputs(tgetstr("me", NULL), 0, tputs_putchar);
}

int		ft_winsize_tosmall(t_select *select)
{
	if ((size_t)ft_lstlen(select->env) - 1 > (((select->win.ws_row - 1) * (select->win.ws_col / select->max_len))))
	{
		ft_display_winsizetosmall(select);
		return (1);
	}
	else
		return (0);
}

void	ft_init_window(t_select *select)
{
	if (ioctl(0, TIOCGWINSZ, &select->win) != -1)
	{
		select->win_count++;
		select->x = 0;
		select->y = 0;
		if(ft_winsize_tosmall(select) != 1)
			ft_list_show(select->env);
	}
}