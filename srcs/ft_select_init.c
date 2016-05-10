/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:25:27 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/29 17:25:28 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		ft_init_select(t_select *select)
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
	select->xdelete = 0;
	select->ydelete = 0;
	select->deletes = 0;
	select->indexdelete = 0;
	select->first_us_delete = 1;
	select->last_len = 0;
}

void		ft_select_reset(t_select *select)
{
	char	buff_env[4096];

	tputs(tgetstr("ve", NULL), 0, tputs_putchar);
	tputs(tgetstr("te", NULL), 0, tputs_putchar);
	if ((select->term_name = getenv("TERM")) == NULL)
		return ;
	if (tgetent(buff_env, select->term_name) != 1)
		return ;
	if (tcgetattr(0, &select->term) == -1)
		return ;
	select->term.c_lflag = (ICANON | ECHO | ISIG);
	if (tcsetattr(0, 0, &select->term) == -1)
		return ;
}

t_select	*ft_struct_select(void)
{
	static t_select	select;

	return (&select);
}
