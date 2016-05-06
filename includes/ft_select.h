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
# include <fcntl.h>


# define TOP ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65))
# define BOTTOM ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66))
# define RIGHT ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67))
# define LEFT ((buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68))
# define SPACE ((buffer[0] == 32))
# define ESC ((buffer[0] == 27 && buffer[1] == 0) && buffer[3] == 0)
# define ENTER ((buffer[0] == 10))
# define IS_ARROW (buffer[0] == 27)
# define CNTRL_C (buffer[0] == 4 || buffer[0] == 3)
# define DELETE (buffer[0] == 127)

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct 		s_env
{
	char			*arg_name;
	int 			is_mr;
	int 			is_us;
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
	int 			cur_col;
	int 			win_count;
	int				max_li;
	int 			last_li;
	int				index;
	int 			count_mr;
	int 			first_process;
	int 			count_del;
	int 			lst_len;
	int 			tty;
	int 			xdelete;
	int 			ydelete;
	int 			deletes;
	int 			indexdelete;
	int 			first_us_delete;
}					t_select;

t_select	*ft_struct_select(void);
void		ft_move_where(t_select *select, char *buffer);
void		ft_term_init(t_select *select);
void		ft_init_select(t_select *select);
int 		tputs_putchar(int c);
void		ft_init_window(t_select *select);

// SIGNAL //
void		ft_check_sig(int i);
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
void  	ft_return_key(t_select *select);
void	ft_delete_key(t_select *select);

void	ft_ue_node(t_select *select);
void	ft_us_node(t_select *select);
void	ft_printf(t_select *select);

// ft_arrow
void	ft_arrow_top(t_select *select);
void	ft_arrow_bot(t_select *select);
void	ft_arrow_left(t_select *select);
void	ft_arrow_right(t_select *select);

//  ft_init_winsize.c 
int	 	ft_init_winsize(t_select *select);

// ft_resize_window.c
void	ft_init_window(t_select *select);
void	ft_key_exit(t_select *select);
void	ft_select_reset(t_select *select);

void	ft_done_value(t_select *select);
void ft_check_status(t_select *select, t_env *env);


#endif