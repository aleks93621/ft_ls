/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:29:17 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		affi_flag_minus_zero(t_flags flag, char *nbr, int e, int tmpeh)
{
	int tmpp;

	tmpp = flag.prec;
	if (flag.zero == 1 && flag.point == 0)
	{
		if (flag.hash == 1)
			affiche_hash(flag);
		while (tmpeh++ < flag.width)
			ft_putchar('0');
		ft_putstr(nbr);
	}
	else
	{
		if (flag.prec >= 0 && flag.prec > e)
			tmpeh = tmpeh + (flag.prec - e);
		while (tmpeh++ < flag.width)
			ft_putchar(' ');
		if (flag.hash == 1)
			affiche_hash(flag);
		if (flag.prec > 0 && flag.prec > e)
			while (tmpp-- > e)
				ft_putchar('0');
		ft_putstr(nbr);
	}
}

static void		affi_flag_minus_un(t_flags flag, char *nbr, int e, int tmpeh)
{
	int tmpp;

	tmpp = flag.prec;
	if (flag.minus == 1)
	{
		if (flag.hash == 1)
			affiche_hash(flag);
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
}

static int		return_valeur(t_flags flag, int tmpeh2, int e)
{
	if (flag.width > tmpeh2 && flag.width > flag.prec)
		e = flag.width;
	else if (flag.prec > e && flag.prec >= flag.width)
		e = (flag.prec - e) + tmpeh2;
	else
		e = tmpeh2;
	return (e);
}

static void		norme_print(t_flags flag, char *nbr, int e, int tmpeh)
{
	if (flag.width > tmpeh || flag.prec > e)
	{
		if (flag.minus == 1)
			affi_flag_minus_un(flag, nbr, e, tmpeh);
		else if (flag.minus == 0)
			affi_flag_minus_zero(flag, nbr, e, tmpeh);
	}
	else
	{
		if (flag.hash == 1)
			affiche_hash(flag);
		ft_putstr(nbr);
	}
}

int				ft_printhex(t_flags flag, va_list ap)
{
	char	*nbr;
	int		e;
	int		tmpeh;
	int		tmpp;
	int		tmpeh2;

	tmpp = flag.prec;
	if (flag.conv == 'x')
		nbr = ft_checker_x(flag, ap);
	else
		nbr = ft_checker_x_maj(flag, ap);
	e = ft_strlen(nbr);
	if (nbr[0] == '0' && nbr[1] == '\0' && (flag.point == 1 || flag.hash == 1))
		e = zero_hex(flag, e);
	else
	{
		tmpeh = e;
		if (flag.hash == 1)
			tmpeh += 2;
		tmpeh2 = tmpeh;
		norme_print(flag, nbr, e, tmpeh);
		e = return_valeur(flag, tmpeh2, e);
	}
	free(nbr);
	return (e);
}
