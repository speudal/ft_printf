/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:20:44 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 03:55:08 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
		char	wrong;
		char	conv;
		char	*options;
		char	*size;
		int		width;
		int		accuracy;
}				t_flags;

int     ft_printf(const char *format, ...);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
char    *ft_strncpy(char *dst, const char *src, size_t len);
int		print_c(va_list ap, t_flags elem);
int		print_s(va_list ap, t_flags elem);
int		print_p(va_list ap, t_flags elem);
int		print_per(t_flags elem);
int		print_d(va_list ap, t_flags elem);
int		print_zd(va_list ap, t_flags elem);
int		print_hd(va_list ap, t_flags elem);
int		print_hhd(va_list ap, t_flags elem);
int		print_ld(va_list ap, t_flags elem);
int		print_lld(va_list ap, t_flags elem);
int		print_i(va_list ap, t_flags elem);
int		print_hi(va_list ap, t_flags elem);
int		print_hhi(va_list ap, t_flags elem);
int		print_li(va_list ap, t_flags elem);
int		print_lli(va_list ap, t_flags elem);
int		print_o(va_list ap, t_flags elem);
int		print_ho(va_list ap, t_flags elem);
int		print_hho(va_list ap, t_flags elem);
int		print_lo(va_list ap, t_flags elem);
int		print_llo(va_list ap, t_flags elem);
int		print_u(va_list ap, t_flags elem);
int		print_hu(va_list ap, t_flags elem);
int		print_hhu(va_list ap, t_flags elem);
int		print_lu(va_list ap, t_flags elem);
int		print_llu(va_list ap, t_flags elem);
int		print_sx(va_list ap, t_flags elem);
int		print_hsx(va_list ap, t_flags elem);
int		print_hhsx(va_list ap, t_flags elem);
int		print_lsx(va_list ap, t_flags elem);
int		print_llsx(va_list ap, t_flags elem);
int		print_bx(va_list ap, t_flags elem);
int		print_hbx(va_list ap, t_flags elem);
int		print_hhbx(va_list ap, t_flags elem);
int		print_lbx(va_list ap, t_flags elem);
int		print_llbx(va_list ap, t_flags elem);
void	print_llld(long long n);
void	print_lllo(unsigned long long n);
void	print_lllu(unsigned long long n);
void	print_lllsx(unsigned long long n);
void	print_lllbx(unsigned long long n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void    *ft_memchr(const void *s, int c, size_t n);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
t_flags	fill_flags(const char *str);
t_flags	*get_flags(const char *str);

# endif
