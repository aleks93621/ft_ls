/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:07:15 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_print_zero_oct(t_flags flag)
{
	int e;
	int tmpw;
	int i;

	i = 0;
	e = 0;
	tmpw = flag.width;
	if (flag.minus == 1 && flag.hash == 1)
		ft_putchar('0');
	if (flag.hash == 1 && flag.width == -1)
		e = 1;
	if (flag.width != -1)
		e = flag.width;
	if (flag.hash == 1)
		tmpw--;
	while (i++ < tmpw)
		ft_putchar(' ');
	if (flag.hash == 1 && flag.minus == 0)
		ft_putchar('0');
	return (e);
}

void			write_zero_spacev2(t_flags flag, int a)
{
	int i;

	i = a;
	while (i < flag.width)
	{
		if (flag.zero != 0 && flag.minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	if (flag.hash == 1)
		ft_putchar('0');
}

static void		prec_aff(t_flags flag, int e)
{
	int tmpw;

	tmpw = flag.width;
	if (flag.prec > e && flag.minus == 0)
		while (tmpw-- > flag.prec)
			ft_putchar(' ');
	else if (flag.prec <= e && flag.minus == 0)
		while (tmpw-- > e)
			ft_putchar(' ');
}

int				prec_checkeroct(t_flags flag, int e)
{
	int tmpw;
	int tmpp;
	int retourn;

	retourn = 0;
	tmpw = flag.width;
	tmpp = flag.prec;
	if (flag.prec != -1 && flag.prec != 0 && flag.width > flag.prec &&
			flag.width > e)
		prec_aff(flag, e);
	else if (flag.width > flag.prec && flag.width > e && flag.minus == 0)
		while (tmpw-- > e)
			ft_putchar(' ');
	if (flag.prec != -1 && flag.prec != 0 && flag.prec > e)
		while (tmpp-- > e)
			ft_putchar('0');
	if (flag.width >= flag.prec)
		retourn = flag.width;
	else if (flag.prec >= flag.width)
		retourn = flag.prec;
	return (retourn);
}

int				ft_printoct(t_flags flag, va_list ap)
{
	int				e;
	char			*nbr;
	int				widthd;

	widthd = flag.width;
	nbr = ft_checker_o(flag, ap);
	e = ft_strlen(nbr);
	ft_printoctt(flag, &e, nbr, widthd);
	free(nbr);
	return (e);
}
