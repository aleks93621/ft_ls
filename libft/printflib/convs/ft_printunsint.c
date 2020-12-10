/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:42:47 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	flagminzer(t_flags flag, char *nbr, int e, int tmpp)
{
	int tmpeh;

	tmpeh = e;
	if (flag.zero == 1 && flag.point == 0)
	{
		while (tmpeh++ < flag.width)
			ft_putchar('0');
	}
	else
	{
		if (flag.prec >= 0 && flag.prec > e)
			tmpeh = tmpeh + (flag.prec - e);
		while (tmpeh++ < flag.width)
			ft_putchar(' ');
		if (flag.prec > 0 && flag.prec > e)
			while (tmpp-- > e)
				ft_putchar('0');
	}
	ft_putstr(nbr);
}

static void	flagminun(t_flags flag, char *nbr, int e, int tmpp)
{
	int tmpeh;

	tmpeh = e;
	if (flag.prec > 0 && flag.prec > e)
	{
		tmpeh = tmpeh + (flag.prec - e);
		while (tmpp-- > e)
			ft_putchar('0');
	}
	ft_putstr(nbr);
	while (tmpeh++ < flag.width)
		ft_putchar(' ');
}

static void	princc(t_flags flag, char *nbr, int *e, int tmpp)
{
	if (nbr[0] == '0' && nbr[1] == '\0' && (flag.point == 1 || flag.hash == 1))
		*e = zero_unsigned(flag, *e);
	else if (flag.width > *e || flag.prec > *e)
	{
		if (flag.minus == 0)
			flagminzer(flag, nbr, *e, tmpp);
		else if (flag.minus == 1)
			flagminun(flag, nbr, *e, tmpp);
	}
	else
		ft_putstr(nbr);
}

int			ft_printunsint(t_flags flag, va_list ap)
{
	int				e;
	char			*nbr;
	int				tmpp;

	tmpp = flag.prec;
	if (flag.prec == -1)
		tmpp = 0;
	nbr = ft_checker_uint(flag, ap);
	e = ft_strlen(nbr);
	princc(flag, nbr, &e, tmpp);
	free(nbr);
	if (flag.width >= flag.prec && flag.width > e)
		return (flag.width);
	else if (flag.prec > flag.width & flag.prec > e)
		return (flag.prec);
	else
		return (e);
}
