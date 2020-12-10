/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:30:14 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include "../../libft/includes/libft.h"

# define CNORM	"\x1B[0m"
# define CROU	"\x1B[31m"
# define CVER	"\x1B[32m"
# define CJAU	"\x1B[33m"
# define CBLE	"\x1B[34m"
# define CMAG	"\x1B[35m"
# define CCYA	"\x1B[36m"
# define CBLA	"\x1B[37m"

typedef struct		s_flags
{
	int			point;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			prec;
	char		size;
	char		conv;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_printunsint(t_flags flag, va_list ap);
int					ft_printchar(t_flags flag, va_list ap);
int					ft_printwchar(t_flags flag, va_list ap);
int					ft_print_space_plus_minus(t_flags flag, int e, char *str);
int					ft_print_space_plus_minusnorm(t_flags
		flag, int e, char *str, char *ok);
int					ft_print_space_plus_minusv2(t_flags flag, int e,
		char *str);
int					ft_print_space_plus_minusnormv2(t_flags flag, int e, char
		*str, char *ok);
int					ft_printstr(t_flags flag, va_list ap);
int					ft_printnbr(t_flags flag, va_list ap);
int					ft_printhex(t_flags flag, va_list ap);
int					ft_printoct(t_flags flag, va_list ap);
int					ft_printvoid_hex(t_flags flag, va_list ap);
int					zero_hex(t_flags flag, int e);
int					zero_unsigned(t_flags flag, int e);
int					ft_print_isnoparam(t_flags flag);
int					ft_printwstr(t_flags flag, va_list ap);
int					prec_checkeroct(t_flags flag, int e);
int					ft_print_zero_oct(t_flags flag);
int					ft_print_binaire(t_flags flag, va_list ap);
int					ft_bonusn(va_list ap, int count);
void				ft_printoctt(t_flags flag, int *e, char *nbr, int width);
int					ft_test(const char *str, int j, va_list ap, t_flags flag);

void				ft_printoctbis(t_flags flag, int *e, char *nbr);
void				write_zero_space(t_flags flag, int a);
void				affiche_hash(t_flags flag);
void				write_zero_spacev2(t_flags flag, int a);
void				ft_octpoint(t_flags flag, int *e, char *nbr, int *widthd);
void				precoct(t_flags flag, char *nbr, int *e);
void				precoctde(t_flags flag, char *nbr, int *e);

int					checker_wstr(wchar_t *wstr);
int					checker_wchar(wchar_t wstr);
char				*ft_checker_x(t_flags flag, va_list ap);
char				*ft_checker_x_maj(t_flags flag, va_list ap);
char				*ft_checker_size_nbr(t_flags flag, va_list ap);
char				*ft_checker_uint(t_flags flag, va_list ap);
char				*ft_checker_o(t_flags flag, va_list ap);

t_flags				ft_fillflag(const char *str, int *k);
t_flags				ft_flaginit(void);

int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
char				*ft_itoa(int n);
char				*ft_itoa_hhuint(unsigned char n);
char				*ft_itoa_hnbr(short n);
char				*ft_itoa_llnbr(long long n);
char				*ft_itoa_hhnbr(signed char n);
char				*ft_itoa_huint(unsigned short n);
char				*ft_itoa_luint(unsigned long n);
char				*ft_itoa_lluint(unsigned long long n);
char				*ft_itoa_lnbr(long n);
char				*ft_itoaunsigned(unsigned int n);
char				*ft_itoabase(unsigned int nbr, int base);
char				*ft_itoabasehh(unsigned char nbr, int base);
char				*ft_itoabaseh(unsigned short nbr, int base);
char				*ft_itoabasel(unsigned long long n, int base);
char				*ft_itoabasemaj(unsigned int nbr, int base);
char				*ft_itoabasemajhh(unsigned char nbr, int base);
char				*ft_itoabasemajh(unsigned short nbr, int base);
char				*ft_itoabasemajl(unsigned long long n, int base);
char				*ft_itoaoctalh(unsigned short n);
char				*ft_itoaoctalhh(unsigned char n);
char				*ft_itoaoctalll(unsigned long long n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_n(char const *s, int n);
void				ft_putstr_len(char const *s, int e);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strnew(size_t size);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwchar(wchar_t chr);
void				ft_putwstr_fd(wchar_t const *str, int fd);
void				ft_putwstr(wchar_t const *str);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *src);
int					ft_isparam(int c);
int					ftc(int c);
void				ft_putnwstr(const wchar_t *str, size_t len);

#endif
