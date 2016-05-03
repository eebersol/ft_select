/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:23:19 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/21 16:49:09 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include <signal.h>

# define TOP ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65))
# define BOTTOM ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66))
# define RIGHT ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67))
# define LEFT ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68))
# define SPACE ((buffer[0] == 32))
# define ESC ((buffer[0] == 27 && buffer[1] == 0))


typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct 		s_env
{
	char			*arg_name;
	int 			is_mr;
}					t_env;

typedef struct 		s_select
{
	t_list			*env;
	t_termios		term;
	t_winsize		win;
	char			*term_name;
	int 			x;
	int 			y;
	size_t			col;
	size_t 			li;
	size_t 			max_len;
	size_t			max_col;
	size_t			size_col;
	int 			cur_col;
	int 			win_count;
	int				max_li;
	int 			last_li;
	int				index;
	int 			first_process;

}					t_select;

t_select	*ft_struct_select(void);
void		ft_move_where(t_select *select, char *bufferfer);
void		ft_term_init(t_select *select);
void		ft_init_select(t_select *select);
int 		tputs_putchar(int c);
void		ft_init_window(t_select *select);

// SIGNAL //
void		ft_check_signal(void);
void		ft_signal_quit(int sig);

// UTIL //
int			ft_lstlen(t_list *list);
void		ft_error(void);
void		ft_put_here(t_select *select, t_env *env);

// GET //
size_t		ft_get_len_max(t_list *list);
void		ft_get_col_line_max(t_select *select);

// LIST //
void		ft_list_show(t_list *list);
void		ft_arg_to_list(t_list **list, char **av);
void	ft_get_col_li(t_select *select);

// ft_space_key.c
void	ft_select_unselect(t_select *select);
void	ft_space_key(t_select *select);
#endif