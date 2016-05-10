/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:57:47 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/29 16:03:12 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_term_init(t_select *select)
{
	char	buff_env[4096];

	if ((select->term_name = getenv("TERM")) == NULL)
		exit(1);
	if (tgetent(buff_env, select->term_name) != 1)
	{
		ft_putendl_fd("ft_select : TERM need a value.", 2);
		exit(1);
	}
	if (tcgetattr(0, &select->term) == -1)
		exit(1);
	select->tty = open("/dev/tty", O_RDWR);
	select->term.c_lflag &= ~(ICANON);
	select->term.c_lflag &= ~(ECHO);
	select->term.c_cc[VMIN] = 1;
	select->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &select->term) == -1)
		exit(1);
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgetstr("ho", NULL), 0, tputs_putchar);
	tputs(tgetstr("vi", NULL), 0, tputs_putchar);
}
