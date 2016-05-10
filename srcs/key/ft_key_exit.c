/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:14:51 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/28 18:14:53 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_key_exit(t_select *select)
{
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgetstr("ho", NULL), 0, tputs_putchar);
	ft_select_reset(select);
	exit(1);
}
