/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:37:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/02 21:37:47 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>


static	t_list	*ft_lstcut(t_list *list, int begin, int end)
{
	t_list	*new_list;
	t_list	*cur;
	t_env 	*env;
	t_env	*new_env;
	int		j;

	j = 0;
	cur = list;
	env = cur->content;
	new_list = list;
	new_env = new_list->content;
	if (begin != 0)
	{
		while (j < begin)
		{
			cur = cur->next;
			j++;
		}
		j = begin;
	}
	else
		j = 0;
	while (j < end)
	{
		new_env = env;
		new_list = new_list->next;
		cur = cur->next;
		j++;
	}
	return (new_list);
}

void	ft_good_col(t_select *select)
{

	t_list	*bonus;
	int i;
	int	end;
	int	begin;

	i = 0;
	bonus = select->env;
	while (i < select->col)
	{
		if (select->x == 0)
		{
			end = select->max_li - 2;
			begin = 0;
			bonus = ft_lstcut(select->env, begin, end);
			ft_list_show(bonus);
			return ;
		}
		else if (select->x == select->max_len * i)
		{
			printf("                                                                                      OUALALALALALALALALALALALAL\n");
			begin = i;
			end = (select->col - i) * select->max_li - 1;
			bonus = ft_lstcut(select->env, begin, end);
			ft_list_show(bonus);
			return ;
		}
		i++;
	}
}