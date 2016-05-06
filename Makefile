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
						ft_list_show.c \
						ft_arg_to_list.c \
						ft_error.c \
						ft_term_init.c  \
						ft_init_select.c \
						ft_move_cursor.c \
						ft_signal.c \
						ft_get_len_max.c \
						ft_space_key.c \
						ft_return_key.c \
						ft_delete_key.c \
						ft_arrows.c \
						winsize/ft_resize_window.c \
						winsize/ft_init_winsize.c \
						ft_key_exit.c


INCLUDES		= -I./libft/includes/ -I./includes/

SRC				= $(addprefix srcs/,$(_SRC))

OBJ				= $(SRC:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

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