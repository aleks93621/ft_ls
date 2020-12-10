/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:23:48 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_zero_spacee(t_flags flag, int a)
{
	int	i;

	i = 0;
	while (i < flag.width - a)
	{
		if (flag.zero != 0 && flag.minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	ft_chrlenval(int chr)
{
	int chr_len;

	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0xFF && MB_CUR_MAX == 1)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	return (chr_len);
}

int			ft_printwchar(t_flags flag, va_list ap)
{
	wchar_t		chr;
	int			chr_len;
	int			count;

	count = 0;
	chr = va_arg(ap, wchar_t);
	if (checker_wchar(chr) == -1)
		return (-1);
	chr_len = ft_chrlenval(chr);
	if (flag.width > 0 && flag.minus == 0)
		count += write_zero_spacee(flag, chr_len);
	ft_putwchar_fd(chr, 1);
	if (flag.width > 0 && flag.minus == 1)
		count += write_zero_spacee(flag, chr_len);
	return (count + chr_len);
}
