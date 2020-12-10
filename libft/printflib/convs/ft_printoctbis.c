/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoctbis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:22:24 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_octpoint(t_flags flag, int *e, char *nbr, int *widthd)
{
	int tmpe;

	tmpe = *e;
	if (flag.prec > *e)
		tmpe = flag.prec;
	if (flag.point == 1)
	{
		*e = prec_checkeroct(flag, *e);
		if (flag.hash == 1 && flag.point == 1)
			ft_putchar('0');
		ft_putstr(nbr);
		if (flag.point == 1 && flag.width > tmpe)
			while ((*widthd)-- > tmpe)
				ft_putchar(' ');
	}
	else if (flag.point == 0)
	{
		*e = flag.width;
		write_zero_spacev2(flag, *e);
		ft_putstr(nbr);
		while ((*widthd)-- > tmpe)
			ft_putchar(' ');
	}
}

void	precoct(t_flags flag, char *nbr, int *e)
{
	int tmpp;

	tmpp = flag.prec;
	if (flag.hash == 1)
		flag.prec++;
	if (nbr[0] == '0')
		flag.prec++;
	while (flag.prec-- > *e)
		ft_putchar('0');
	if (nbr[0] != '0')
		ft_putstr(nbr);
	*e = tmpp;
}

void	precoctde(t_flags flag, char *nbr, int *e)
{
	if (nbr[0] == '0' && nbr[1] == '\0')
		*e = 0;
	if (nbr[0] == '0' && nbr[1] == '\0' && flag.hash == 1)
		(*e)++;
	if (flag.hash == 1)
		ft_putchar('0');
	if (nbr[0] != '0')
		ft_putstr(nbr);
}

void	ft_printoctbis(t_flags flag, int *e, char *nbr)
{
	if (flag.point == 1)
		*e = prec_checkeroct(flag, *e);
	else
	{
		write_zero_spacev2(flag, *e);
		*e = flag.width;
	}
	if (flag.hash == 1 && flag.point == 1)
		ft_putchar('0');
	ft_putstr(nbr);
}

void	ft_printoctt(t_flags flag, int *e, char *nbr, int widthd)
{
	if (flag.hash == 1)
		(*e)++;
	if (nbr[0] == '0' && nbr[1] == '\0' && flag.point != 1 && flag.width == -1)
	{
		if (flag.hash == 1)
			(*e)--;
		ft_putstr(nbr);
	}
	else if (nbr[0] == '0' && nbr[1] == '\0' &&
			(flag.prec == -1 || flag.prec == 0) && flag.point == 1)
		*e = ft_print_zero_oct(flag);
	else if ((flag.width != -1 || flag.prec != -1) && flag.minus == 0 &&
			(*e <= flag.width || *e <= flag.prec))
		ft_printoctbis(flag, *&e, nbr);
	else if (flag.width != -1 && flag.minus != 0 && *e < flag.width)
		ft_octpoint(flag, *&e, nbr, &widthd);
	else if (flag.prec > *e && flag.width == -1)
		precoct(flag, nbr, *&e);
	else
		precoctde(flag, nbr, *&e);
}
