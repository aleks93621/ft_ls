/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:55:21 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		return_val(t_flags flag, int e)
{
	if (flag.point == 1 && flag.prec < 1 && flag.width < 1)
		return (0);
	else if (flag.width > flag.prec && flag.width >= e)
		return (flag.width);
	else if (flag.prec > e && flag.prec >= flag.width)
		return (flag.prec);
	else if (flag.hash == 1 && flag.point == 0 && flag.width < 1)
		return (1);
	else if (flag.prec == 1 && (flag.width == 0 || flag.width == -1))
		return (1);
	else
		return (0);
}

static void		print_flag_zero(t_flags flag, int e)
{
	int tmpeh;
	int tmpp;

	tmpp = flag.prec;
	tmpeh = e;
	if (flag.prec >= 0 && flag.prec > e)
		tmpeh = tmpeh + (flag.prec - e);
	while (tmpeh++ < flag.width)
	{
		if (flag.zero == 1 && flag.point == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (flag.prec > 0 && flag.prec > e)
		while (tmpp-- > e)
			ft_putchar('0');
	if (flag.prec > 0)
		ft_putchar('0');
}

int				zero_unsigned(t_flags flag, int e)
{
	int tmpeh;
	int tmpp;

	tmpp = flag.prec;
	tmpeh = e;
	if (flag.minus == 0)
		print_flag_zero(flag, e);
	else
	{
		if (flag.hash == 1 && flag.point == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		while (tmpeh++ < flag.width)
			ft_putchar(' ');
	}
	return (return_val(flag, e));
}
