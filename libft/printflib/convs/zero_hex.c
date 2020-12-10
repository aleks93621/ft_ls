/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:55:21 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		printhexminus(t_flags flag, int e, int *retourn)
{
	int tmpp;

	tmpp = flag.prec;
	if (flag.plus == 2 && flag.zero == 0)
	{
		ft_putstr("0x");
		*retourn += 2;
	}
	if (flag.prec > 0 && flag.prec > e)
		while (tmpp-- > e)
			ft_putchar('0');
	if (flag.prec > e && flag.width < flag.prec && flag.hash == 0)
		ft_putchar('0');
	else if (flag.hash == 1 && (flag.prec > 1 || flag.point == 0))
		ft_putchar('0');
	else if (flag.prec == 1 && (flag.width == 0 || flag.width == -1))
		ft_putchar('0');
	else if (flag.prec > 0 || flag.width > 0)
		ft_putchar(' ');
}

static void		hexminus(t_flags flag, int e, int *retourn)
{
	int tmpeh;

	tmpeh = e;
	if (flag.prec >= 0 && flag.prec > e)
		tmpeh = tmpeh + (flag.prec - e);
	if (flag.plus == 2)
		tmpeh += 2;
	if (flag.plus == 2 && flag.zero == 1)
	{
		ft_putstr("0x");
		*retourn += 2;
	}
	while (tmpeh++ < flag.width)
	{
		if (flag.zero == 1 && flag.point == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	printhexminus(flag, e, *&retourn);
}

static void		hexplus(t_flags flag, int e)
{
	int tmpeh;
	int tmpp;

	tmpp = flag.prec;
	tmpeh = e;
	if (flag.plus == 2)
		ft_putstr("0x");
	if (flag.hash == 1 && flag.point == 0)
		ft_putchar('0');
	else if (flag.prec > 0)
		ft_putchar('0');
	else
		ft_putchar(' ');
	if (flag.prec > 0 && flag.prec > e)
	{
		tmpeh = tmpeh + flag.prec - 1;
		while (tmpp-- > e)
			ft_putchar('0');
	}
	if (flag.plus == 2)
		tmpeh += 2;
	while (tmpeh++ < flag.width)
		ft_putchar(' ');
}

int				zero_hex(t_flags flag, int e)
{
	int retourn;

	retourn = 0;
	if (flag.minus == 0)
		hexminus(flag, e, &retourn);
	else
		hexplus(flag, e);
	if (flag.point == 1 && flag.prec < 1 && flag.width < 1)
		return (retourn);
	else if (flag.width > flag.prec && flag.width >= e)
		return (flag.width);
	else if (flag.prec > e && flag.prec >= flag.width)
	{
		if (flag.plus == 2)
			flag.prec += 2;
		return (flag.prec);
	}
	else if (flag.hash == 1 && flag.point == 0 && flag.width < 1)
		return (retourn + 1);
	else if (flag.prec == 1 && (flag.width == 0 || flag.width == -1))
		return (1);
	else
		return (retourn);
}
