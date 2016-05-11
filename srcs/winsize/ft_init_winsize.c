/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_winsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:49:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/30 19:49:20 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static	void	ft_display_required(t_select *select)
{
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
}

static	void	ft_display_current(t_select *select)
{
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

static	void	ft_display_winsize(t_select *select)
{
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgoto(NULL, (select->col / 2), (select->max_li / 2)),
		0, tputs_putchar);
	ft_display_required(select);
	ft_display_current(select);
}

int				ft_init_winsize(t_select *select)
{
	ft_get_col_li(select);
	if (ft_lstlen(select->env) - 1 >
		(((select->max_li - 1) * (select->max_col / select->max_len)))
		&& ((select->max_col - (select->max_len * (select->col)))) <=
		select->last_len)
	{
		ft_display_winsize(select);
		return (1);
	}
	else
		return (0);
}
