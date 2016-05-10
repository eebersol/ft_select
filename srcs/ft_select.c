/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:14:51 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/28 18:14:53 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_check_event(void)
{
	ft_check_sig(0);
	signal(SIGTSTP, ft_check_sig);
	signal(SIGCONT, ft_check_sig);
	signal(SIGINT, ft_check_sig);
	signal(SIGQUIT, ft_check_sig);
}

void	ft_spot_control(t_select *select)
{
	char	buffer[2000];
	int		ret;

	ret = 0;
	while ((ret = read(0, buffer, 5)) != -1)
	{
		if (ESC)
			ft_key_exit(select);
		else if (DELETE)
			ft_delete_key(select);
		else if (IS_ARROW)
			ft_move_where(select, buffer);
		else if (ENTER)
			ft_return_key(select);
		else if (CNTRL_C)
			ft_key_exit(select);
		else if (SPACE)
		{
			ft_space_key(select);
		}
		else if (BACK_SPACE)
			ft_delete_key(select);
		ft_bzero(buffer, 5);
	}
}

int		main(int ac, char **av, char **tmp_env)
{
	t_select		*select;

	(void)tmp_env;
	(void)ac;
	select = ft_struct_select();
	if (tmp_env[0] == NULL)
	{
		ft_putendl_fd("ft_select : need env not empty.", 2);
		exit(1);
	}
	if (!av[1])
		ft_error();
	ft_init_select(select);
	ft_term_init(select);
	ft_arg_to_list(&select->env, av);
	ft_check_event();
	if (ft_init_winsize(select) != 1)
		ft_list_show(select->env);
	while (42)
	{
		ft_check_sig(0);
		ft_spot_control(select);
	}
}
