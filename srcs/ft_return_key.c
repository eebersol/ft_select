/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void  	ft_return_key(t_select *select)
{
	t_list *list;
	t_env 	*env;
	int 	i;
	
	i = 0;
	list = select->env;
	env = list->content;
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	tputs(tgetstr("ho", NULL), 0, tputs_putchar);
	while (list)
	{
		env = list->content;
		if (env->is_mr == 1)
		{
			tputs(tgetstr("me", NULL), 0, tputs_putchar);
			ft_putstr(env->arg_name);
			i++;
			if (i < select->count_mr)
				ft_putchar(' ');
		}
		list = list->next;
	}
	exit (0);
}
