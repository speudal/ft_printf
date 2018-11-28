# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:08:51 by tduval            #+#    #+#              #
#    Updated: 2018/11/28 14:11:47 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CONVS	=	conv.a

SRCS	=	ft_putchar.c		\
			ft_putstr.c			\
			ft_putnbr.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_isdigit.c		\
			ft_strchr.c			\
			ft_atoi.c			\
			ft_strcmp.c			\
			ft_strncpy.c		\
			ft_memchr.c			\
			ft_strnew.c			\
			ft_memalloc.c		\
			ft_memset.c			\
			fill_flags.c		\
			get_flags.c			\
			ft_printf.c			\
			print_c.c			\
			print_s.c			\
			print_p.c			\
			print_per.c			\
			print_d.c			\
			print_hd.c			\
			print_hhd.c			\
			print_ld.c			\
			print_lld.c			\
			print_i.c			\
			print_hi.c			\
			print_hhi.c			\
			print_li.c			\
			print_lli.c			\
			print_o.c			\
			print_ho.c			\
			print_hho.c			\
			print_lo.c			\
			print_llo.c			\
			print_u.c			\
			print_hu.c			\
			print_hhu.c			\
			print_lu.c			\
			print_llu.c			\
			print_sx.c			\
			print_hsx.c			\
			print_hhsx.c		\
			print_lsx.c			\
			print_llsx.c		\
			print_bx.c			\
			print_hbx.c			\
			print_hhbx.c		\
			print_lbx.c			\
			print_llbx.c		\

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
