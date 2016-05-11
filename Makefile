# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 19:11:03 by eebersol          #+#    #+#              #
#    Updated: 2016/04/08 19:11:04 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program

NAME			= ft_select

LIB				=	./libft/libft.a

_SRC			= 	ft_select.c \
						ft_select_init.c \
						ft_error.c \
						ft_term_init.c  \
						ft_signal.c \
						utils/ft_get_len_max.c \
						utils/ft_arg_to_list.c \
						utils/ft_list_show.c \
						utils/ft_tputs.c \
						utils/ft_free_node.c \
						utils/ft_get_col_li_max.c \
						utils/ft_check_first_index.c \
						winsize/ft_resize_window.c \
						winsize/ft_init_winsize.c \
						key/ft_key_exit.c \
						key/ft_key_arrows.c \
						key/ft_key_delete.c \
						key/ft_key_space.c \
						key/ft_key_return.c \
						key/ft_move_where.c


INCLUDES		= -I./libft/includes/ -I./includes/

SRC				= $(addprefix srcs/,$(_SRC))

OBJ				= $(SRC:.c=.o)

CFLAGS			= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -ltermcap -o $(NAME)
	@echo $(NAME)" compiled"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Clean all .o files"

fclean:	clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all