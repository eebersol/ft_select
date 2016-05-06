/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 22:27:36 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/28 22:27:38 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_signal_resize(int sig)
{
	(void)(sig);
	ft_init_window(ft_struct_select());
}

void 	ft_signal_background(int sig)
{
	char	cp[2];

	cp[0] = ft_struct_select()->term.c_cc[VSUSP];
	cp[1] = '\0';
	(void)sig;
	ft_init_select(ft_struct_select());
	signal(SIGCONT, ft_check_sig);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void	ft_signal_foreground(int sig)
{
	signal(SIGTSTP, ft_check_sig);
	signal(SIGQUIT, ft_check_sig);
	ft_term_init(ft_struct_select());
	ft_init_window(ft_struct_select());
	(void)sig;
}

void	ft_signal_quit(int sig)
{
	(void)sig;
	ft_select_reset(ft_struct_select());
	exit(0);
}

void			ft_check_sig(int i)
{
	signal(SIGWINCH, ft_signal_resize);
	if (i == SIGTSTP)
		ft_signal_background(i);
	else if (i == SIGCONT)
		ft_signal_foreground(i);
	else if (i == SIGINT)
		ft_signal_quit(i);
	else if (i == SIGQUIT)
		ft_signal_quit(i);
	(void)i;
}
