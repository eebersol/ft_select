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

# define TOP ((b[0] == 27 && b[1] == 91 && b[2] == 65))
# define BOTTOM ((b[0] == 27 && b[1] == 91 && b[2] == 66))
# define RIGHT ((b[0] == 27 && b[1] == 91 && b[2] == 67))
# define LEFT ((b[0] == 27 && b[1] == 91 && b[2] == 68))
# define SPACE ((b[0] == 32))
# define ESC ((b[0] == 27 && b[1] == 0) && b[3] == 0)
# define ENTER ((b[0] == 10))
# define IS_ARROW (b[0] == 27)
# define CNTRL_C (b[0] == 4 || b[0] == 3)
# define BACK_SPACE (b[0] == 127)
# define DELETE ((b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126))

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

typedef struct		s_env
{
	char			*arg_name;
	int				is_mr;
	int				is_us;
}					t_env;

typedef struct		s_select
{
	t_list			*env;
	t_termios		term;
	t_winsize		win;
	char			*term_name;
	int				x;
	int				y;
	int				col;
	int				li;
	int				max_len;
	int				max_col;
	int				cur_col;
	int				win_count;
	int				max_li;
	int				last_li;
	int				index;
	int				count_mr;
	int				first_process;
	int				count_del;
	int				lst_len;
	int				tty;
	int				xdelete;
	int				ydelete;
	int				deletes;
	int				indexdelete;
	int				first_us_delete;
	int				last_len;
}					t_select;

void				ft_error(void);
void				ft_init_select(t_select *select);
t_select			*ft_struct_select(void);
void				ft_check_sig(int i);
void				ft_signal_quit(int sig);
void				ft_signal_foreground(int sig);
void				ft_signal_background(int sig);
void				ft_signal_resize(int sig);
void				ft_term_init(t_select *select);
void				ft_select_reset(t_select *select);
int					ft_reset_term(t_select *select);
void				ft_return_key(t_select *select);
void				ft_key_exit(t_select *select);
void				ft_delete_key(t_select *select);
void				ft_space_key(t_select *select);
void				ft_arrow_top(t_select *select);
void				ft_arrow_bot(t_select *select);
void				ft_arrow_left(t_select *select);
void				ft_arrow_right(t_select *select);
void				ft_ue_node(t_select *select);
void				ft_us_node(t_select *select);
void				ft_move_where(t_select *select, char *b);
int					ft_lstlen(t_list *list);
void				ft_arg_to_list(t_list **list, char **av);
size_t				ft_get_len_max(t_list *list, t_select *select);
void				ft_get_col_line_max(t_select *select);
void				ft_list_show(t_list *list);
int					tputs_putchar(int c);
void				ft_put_here(t_select *select, t_env *env);
void				ft_get_col_li(t_select *select);
void				ft_check_status(t_select *select, t_env *env);
void				ft_free_node(void *content, size_t size);
void				ft_get_col_li(t_select *select);
void				ft_check_first_index(t_select *select);
int					ft_init_winsize(t_select *select);
void				ft_init_window(t_select *select);

#endif
