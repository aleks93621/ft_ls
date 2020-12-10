/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:39:21 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_print_zero(t_flags flag)
{
	int i;
	int e;

	e = 0;
	if (flag.width != -1)
		e = flag.width;
	i = 0;
	while (i++ < flag.width)
		ft_putchar(' ');
	return (e);
}

static int		ft_print_plus_space(t_flags flag, char *nbr, int j)
{
	int e;

	e = 0;
	if (flag.plus != 0 && nbr[0] != '-')
	{
		ft_putchar('+');
		ft_putstr(nbr);
		e++;
	}
	else if (flag.plus == 0 && flag.space != 0 && nbr[0] != '-')
	{
		ft_putchar(' ');
		ft_putstr(nbr);
		e++;
	}
	e = e + j;
	return (e);
}

int				ft_printnbr(t_flags flag, va_list ap)
{
	int		e;
	char	*nbr;

	nbr = ft_checker_size_nbr(flag, ap);
	e = ft_strlen(nbr);
	if (nbr[0] == '0' && nbr[1] == '\0' && (flag.prec == -1 || flag.prec == 0)
			&& flag.point == 1)
		e = ft_print_zero(flag);
	else if (nbr[0] == '-' && (flag.prec != -1 || flag.width != -1) &&
			(flag.prec > e - 1 || flag.width > e))
		e = ft_print_space_plus_minus(flag, e, nbr);
	else if (nbr[0] != '-' && (flag.plus != 0 || flag.prec != -1 ||
				flag.width != -1) && (flag.prec > e || flag.width > e))
		e = ft_print_space_plus_minusv2(flag, e, nbr);
	else if (flag.plus != 0 && nbr[0] != '-')
		e = ft_print_plus_space(flag, nbr, e);
	else if (flag.plus == 0 && flag.space != 0 && nbr[0] != '-')
		e = ft_print_plus_space(flag, nbr, e);
	else
		ft_putstr(nbr);
	free(nbr);
	return (e);
}
