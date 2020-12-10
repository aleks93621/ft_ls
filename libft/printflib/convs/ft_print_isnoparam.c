/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_isnoparam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:19:41 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	affichee(t_flags flag, int e, int tmpeh)
{
	if (flag.width > e || flag.prec > e)
	{
		if (flag.minus == 0)
		{
			if (flag.zero == 0)
				while (tmpeh++ < flag.width)
					ft_putchar(' ');
			else if (flag.zero == 1)
				while (tmpeh++ < flag.width)
					ft_putchar('0');
			ft_putchar(flag.conv);
		}
		else if (flag.minus == 1)
		{
			ft_putchar(flag.conv);
			while (tmpeh++ < flag.width)
				ft_putchar(' ');
		}
	}
	else
		ft_putchar(flag.conv);
}

int			ft_print_isnoparam(t_flags flag)
{
	int e;
	int tmpeh;
	int tmpp;

	tmpp = flag.prec;
	e = 1;
	tmpeh = 1;
	affichee(flag, e, tmpeh);
	if (flag.width >= flag.prec && flag.width > e)
		return (flag.width);
	else
		return (e);
}
