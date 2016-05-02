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

static void		ft_signal_quit(int sig)
{
	(void)sig;
	return ;
}

void			ft_check_signal(void)
{
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGINT, ft_signal_quit);
	signal(SIGTSTP, ft_signal_background;
	signal(SIGWINCH, ft_signal_resize);
	signal(SIGTSTP, ft_select_foreground);
}

