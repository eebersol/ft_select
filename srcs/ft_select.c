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

void	ft_spot_control(t_select *select)
{
	char	buffer[2000];
	int 	ret;

 	ret = 0;
 	while ((ret = read(0, buffer, 5)) != -1)
 	{
 		if (IS_ARROW)
		{
			ft_move_where(select, buffer);
			break ;
		}
		else if (ENTER)
			ft_save_select(select);
		else if (CNTRL_C)
			exit(1);
	}
}

int	ft_reset_term(t_select *select)
{
	if (tcgetattr(0, &select->term) == -1)
		return (-1);
	select->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &select->term) == -1)
		return (-1);
	return (0);
}

t_select	*ft_struct_select(void)
{
	static t_select	select;

	return (&select);
}

int		main(int ac, char **av, char **tmp_env)
{
	t_select		*select;

	(void)tmp_env;
	(void)ac;
	select = ft_struct_select();
	if (!av[1])
		ft_error();
	ft_init_select(select);
	ft_term_init(select);
	ft_check_signal();
	ft_arg_to_list(&select->env, av);
	ft_list_show(select->env);
	while (1)
	{
		ft_spot_control(select);
	//	ft_term_init(select);
	//	ft_reset_term(select);
	}
}
