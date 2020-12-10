/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:36:15 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		write_zero_spacee(t_flags flag, int a)
{
	int		i;

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

static int		ft_wstr(const wchar_t *wstr, int len)
{
	int		count;

	count = 0;
	while ((*wstr) && count < len)
	{
		if (*wstr <= 0x7F)
			count++;
		else if (*wstr <= 0xFF && MB_CUR_MAX <= 1)
			count++;
		else if (*wstr <= 0x7FF)
			count += 2;
		else if (*wstr <= 0xFFFF)
			count += 3;
		else if (*wstr <= 0x10FFFF)
			count += 4;
		if (count <= len)
			ft_putwchar_fd(*wstr++, 1);
	}
	return (count);
}

static int		ft_wstrprec(const wchar_t *wstr, int max)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while ((*wstr) && count < max)
	{
		if (*wstr <= 0x7F)
			count++;
		else if (*wstr <= 0x7FF)
			count += 2;
		else if (*wstr <= 0xFFFF)
			count += 3;
		else if (*wstr <= 0x10FFFF)
			count += 4;
		if (count <= max)
			i = count;
		wstr++;
	}
	return (i);
}

static int		ft_wstrlen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (*wstr)
	{
		if (*wstr <= 0x7F)
			i++;
		else if (*wstr <= 0x7FF)
			i += 2;
		else if (*wstr <= 0xFFFF)
			i += 3;
		else if (*wstr <= 0x10FFFF)
			i += 4;
		wstr++;
	}
	return (i);
}

int				ft_printwstr(t_flags flag, va_list ap)
{
	int		count;
	wchar_t	*wstr;
	int		len;

	count = 0;
	if ((wstr = (wchar_t*)va_arg(ap, wchar_t*)) == NULL)
		wstr = L"(null)";
	if (checker_wstr(wstr) == -1)
		return (-1);
	len = ft_wstrlen(wstr);
	if (flag.prec > -1)
		len = ft_wstrprec(wstr, flag.prec);
	if (flag.width > 0 && flag.minus == 0)
		count += write_zero_spacee(flag, len);
	count += ft_wstr(wstr, len);
	if (flag.width > 0 && flag.minus != 0)
		count += write_zero_spacee(flag, len);
	return (count);
}
