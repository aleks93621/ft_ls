/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:32:39 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_printstrv4(t_flags flag, int e)
{
	int tmpeh;

	tmpeh = e;
	if (flag.prec != -1 && flag.prec < e && e > 0)
		tmpeh = flag.prec;
	if (flag.width >= flag.prec && (flag.prec < e || (flag.prec > e &&
					flag.width > e)) && flag.prec > -1 && flag.width > tmpeh)
		return (flag.width);
	else if ((flag.prec == -1 || e == 0) && flag.width > e)
		return (flag.width);
	else if (flag.prec <= e && flag.width > flag.prec)
		return (flag.width);
	else if (e == 0 && flag.width < 1)
		return (0);
	else if (flag.prec > flag.width && flag.prec < e)
		return (flag.prec);
	else if (flag.width > e && flag.prec > e && flag.prec > flag.width)
		return (flag.width);
	else
		return (e);
}

static void		ft_printstrv3(t_flags flag, char *nbr, int e, int tmpeh)
{
	if (flag.prec > -1 && e > 0 && flag.prec < e)
		ft_putstr_len(nbr, flag.prec);
	else
		ft_putstr(nbr);
	if (flag.width > 0)
		while (tmpeh++ < flag.width)
			ft_putchar(' ');
}

static void		ft_printstrv2(t_flags flag, char *nbr, int e, int tmpeh)
{
	if (flag.minus == 0)
	{
		if (flag.width > 0)
		{
			if (flag.zero == 1)
				while (tmpeh++ < flag.width)
					ft_putchar('0');
			else
				while (tmpeh++ < flag.width)
					ft_putchar(' ');
		}
		if (flag.prec > -1 && e > 0 && flag.prec < e)
			ft_putstr_len(nbr, flag.prec);
		else
			ft_putstr(nbr);
	}
	else if (flag.minus == 1)
		ft_printstrv3(flag, nbr, e, tmpeh);
}

int				ft_printstr(t_flags flag, va_list ap)
{
	int		e;
	char	*nbr;
	int		tmpp;
	int		tmpeh;

	tmpp = flag.prec;
	if (flag.conv == 'S' || (flag.size == 'l' && flag.conv == 's'))
		return (ft_printwstr(flag, ap));
	if ((nbr = va_arg(ap, char*)) == NULL)
		nbr = "(null)";
	e = ft_strlen(nbr);
	if (flag.prec > -1 && e > 0 && flag.prec < e)
		tmpeh = flag.prec;
	else
		tmpeh = e;
	if (flag.width > e || flag.prec >= 0)
		ft_printstrv2(flag, nbr, e, tmpeh);
	else
		ft_putstr(nbr);
	return (ft_printstrv4(flag, e));
}
