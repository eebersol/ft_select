/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_free_node(void *content, size_t size)
{
	t_env	*env;

	(void)size;
	env = content;
	if (!content)
		return ;
	if (env->arg_name)
		ft_strdel(&(env->arg_name));
	free(env);
}

void	ft_delete_key(t_select *select)
{
	if (ft_lstlen(select->env) == 0)
		exit (1);
	else
		ft_lstdel_at(&select->env, select->index, &ft_free_node);
	select->y--;
	if (select->y == 0)
	{
		select->x -= select->max_len;
		select->y = select->max_li - 1;
	}
	//select->x = 0;
	//select->y = 0;
	ft_list_show(select->env);
}