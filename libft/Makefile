#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 13:01:06 by eebersol          #+#    #+#              #
#    Updated: 2016/03/14 18:19:55 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME 	= libft.a

_SRCS 	= ft_memset.c \
	   	ft_bzero.c \
	   	ft_memcpy.c \
	   	ft_memccpy.c \
	   	ft_memmove.c \
	   	ft_memchr.c \
	   	ft_memcmp.c \
	   	ft_strlen.c \
	   	ft_strdup.c \
	   	ft_strcpy.c \
	   	ft_strncpy.c \
	   	ft_strcat.c \
	   	ft_strncat.c \
	   	ft_strlcat.c \
	   	ft_strrchr.c \
		ft_strchr.c \
	   	ft_strstr.c \
	   	ft_strnstr.c \
	   	ft_strcmp.c \
	   	ft_strncmp.c \
	   	ft_atoi.c \
	   	ft_isalpha.c \
	   	ft_isdigit.c \
	   	ft_isalnum.c \
	   	ft_isascii.c \
	   	ft_isprint.c \
	   	ft_toupper.c \
	   	ft_tolower.c \
	   	ft_memalloc.c \
	   	ft_strdel.c \
	   	ft_strclr.c \
	   	ft_striter.c \
	   	ft_strequ.c \
		ft_strnequ.c \
	   	ft_putchar.c \
	   	ft_putstr.c \
	   	ft_putendl.c \
	   	ft_putnbr.c \
	   	ft_putchar_fd.c \
	   	ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_strsub.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strjoin.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strtrim.c \
		ft_strnew.c \
		ft_strmapi.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_positive.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstdel_at.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstadd.c \
		ft_lstadd_back.c \
		ft_lstrev.c \
		ft_lstiter_if.c \
		ft_lstsort.c \
		ft_lstget_at.c \
		ft_strlenchar.c \
		ft_part_nbr.c \
		ft_len_int.c \
		ft_sign_int.c \
		ft_chartrim.c \
		ft_isblank.c \
		ft_isspace.c \
		ft_xdigit.c \
		ft_freejoin.c \
		ft_iscntrl.c \
		get_next_line.c \
		**ft_word_to_tab.c \
		ft_tab_free.c \
		ft_tab_len.c \
		ft_isalphanumeric.c \

SRCS 	= $(addprefix srcs/,$(_SRCS))

SRCS_O   = $(subst .c,.o,$(_SRCS))

CFLAGS 	= -Wall -Wextra -Werror -c

CC 		= gcc $(CFLAGS)

all		: $(NAME)

$(NAME) :
	@$(CC) $(SRCS) -Iincludes
	@mkdir bin
	@ar rc $(NAME) $(SRCS_O)
	@ranlib $(NAME)
	@mv $(SRCS_O) bin/
	@echo "Lib compiled"

$(SRCS) : $(NAME)
	@$(CC)  $(_SRCS)

clean	: 
	@/bin/rm -rf bin
	@echo "clean .o"

fclean	: clean
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "Clean all"

re		: fclean all

.PHONY: all, clean, fclean, re
