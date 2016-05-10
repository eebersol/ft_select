/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:25:31 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/30 20:25:32 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_get_col_line_max(t_select *select)
{
	select->col = tgetnum("co");
	select->li = tgetnum("li");
	select->max_col = (select->col / select->max_len);
}

size_t	ft_get_len_max(t_list *list, t_select *select)
{
	t_env	*env;
	t_list	*cur;
	size_t	max_len;

	select = ft_struct_select();
	cur = list;
	max_len = 0;
	while (cur)
	{
		env = cur->content;
		if (ft_strlen(env->arg_name) > max_len)
			max_len = ft_strlen(env->arg_name);
		cur = cur->next;
	}
	cur = list;
	while (cur)
	{
		env = cur->content;
		(ft_struct_select())->max_len = max_len;
		cur = cur->next;
	}
	select->last_len = ft_strlen(env->arg_name);
	return (max_len);
}
