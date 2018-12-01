# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:08:51 by tduval            #+#    #+#              #
#    Updated: 2018/12/01 00:19:33 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Werror -Wextra -I.

SRCS	=	ft_printf.c					\
			./libft/ft_putchar.c		\
			./libft/ft_putstr.c			\
			./libft/ft_memdel.c			\
			./libft/ft_putnbr.c			\
			./libft/ft_strlen.c			\
			./libft/ft_strdup.c			\
			./libft/ft_isdigit.c		\
			./libft/ft_strchr.c			\
			./libft/ft_atoi.c			\
			./libft/ft_strcmp.c			\
			./libft/ft_strncpy.c		\
			./libft/ft_memchr.c			\
			./libft/ft_strnew.c			\
			./libft/ft_memalloc.c		\
			./libft/ft_memset.c			\
			./srcs/dispatcher.c			\
			./srcs/fill_flags.c			\
			./srcs/get_flags.c			\
			./srcs/print_c.c			\
			./srcs/print_s.c			\
			./srcs/print_p.c			\
			./srcs/print_per.c			\
			./srcs/print_d.c			\
			./srcs/print_hd.c			\
			./srcs/print_hhd.c			\
			./srcs/print_ld.c			\
			./srcs/print_lld.c			\
			./srcs/print_i.c			\
			./srcs/print_hi.c			\
			./srcs/print_hhi.c			\
			./srcs/print_li.c			\
			./srcs/print_lli.c			\
			./srcs/print_o.c			\
			./srcs/print_ho.c			\
			./srcs/print_hho.c			\
			./srcs/print_lo.c			\
			./srcs/print_llo.c			\
			./srcs/print_u.c			\
			./srcs/print_hu.c			\
			./srcs/print_hhu.c			\
			./srcs/print_lu.c			\
			./srcs/print_llu.c			\
			./srcs/print_sx.c			\
			./srcs/print_hsx.c			\
			./srcs/print_hhsx.c			\
			./srcs/print_lsx.c			\
			./srcs/print_llsx.c			\
			./srcs/print_bx.c			\
			./srcs/print_hbx.c			\
			./srcs/print_hhbx.c			\
			./srcs/print_lbx.c			\
			./srcs/print_llbx.c			\
			./paddings/padding_d.c		\
			./paddings/padding_u.c		\
			./paddings/padding_o.c		\
			./paddings/padding_sx.c		\
			./paddings/padding_bx.c

OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\x1b[32;01m[LIBFTPRINTF COMPILED]"

sale :
	gcc -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
