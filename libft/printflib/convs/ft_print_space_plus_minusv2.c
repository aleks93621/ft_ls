/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_plus_minusv2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:28:48 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_normetroi(t_flags flag, int e, char *str)
{
	int tmp;

	tmp = flag.width;
	if (flag.plus != 0 || flag.space != 0)
		e++;
	if (flag.plus != 0 && (flag.width == -1 || flag.zero != 0))
		ft_putchar('+');
	else if (flag.space != 0 && flag.plus == 0)
		ft_putchar(' ');
	while (tmp-- > e)
	{
		if (flag.zero != 0)
			ft_putchar('0');
		else if (flag.minus == 0)
			ft_putchar(' ');
	}
	if (flag.plus != 0 && flag.width != -1 && flag.zero == 0)
		ft_putchar('+');
	ft_putstr(str);
	return (flag.width);
}

static int		ft_normeun(t_flags flag, int j, int e, char *str)
{
	int tmp2;
	int tmpj;

	tmpj = j;
	tmp2 = flag.prec;
	while (j--)
		ft_putchar(' ');
	if (flag.plus != 0)
	{
		flag.prec++;
		ft_putchar('+');
	}
	else if (flag.space != 0 && flag.plus == 0)
	{
		flag.prec++;
		ft_putchar(' ');
	}
	while ((tmp2-- - e) > 0)
		ft_putchar('0');
	ft_putstr(str);
	return (tmpj + flag.prec);
}

static int		ft_normedeu(t_flags flag, int j, int e, char *str)
{
	int tmp2;
	int tmpj;

	tmpj = j;
	if (flag.plus != 0)
	{
		e++;
		flag.prec++;
		ft_putchar('+');
	}
	else if (flag.space != 0 && flag.plus == 0)
	{
		e++;
		flag.prec++;
		ft_putchar(' ');
	}
	tmp2 = flag.prec;
	while ((tmp2-- - e) > 0)
		ft_putchar('0');
	ft_putstr(str);
	while (j--)
		ft_putchar(' ');
	return (tmpj + flag.prec);
}

static int		flag_longu(t_flags flag)
{
	int i;

	i = 0;
	if ((flag.width != -1) && (flag.width > flag.prec) && flag.prec != -1 &&
			(flag.plus != 0 || flag.space != 0))
		i = flag.width - flag.prec - 1;
	else if ((flag.width != -1) && (flag.width > flag.prec) && flag.prec != -1
			&& (flag.plus == 0 || flag.space == 0))
		i = flag.width - flag.prec;
	return (i);
}

int				ft_print_space_plus_minusv2(t_flags flag, int e, char *str)
{
	int j;
	int compt;

	compt = 0;
	j = flag_longu(flag);
	if (flag.width > e && j > -1 && flag.minus == 0 && flag.prec > e - 1)
		compt = ft_normeun(flag, j, e, str);
	else if (flag.width > e && j > -1 && flag.minus != 0 && flag.prec > e - 1)
		compt = ft_normedeu(flag, j, e, str);
	else if ((flag.width > e) && (j != 0) && flag.minus == 0)
		compt = ft_print_space_plus_minusnormv2(flag, e, str, "trois");
	else if (flag.width > e && flag.minus == 0 && flag.width > flag.prec)
		compt = ft_normetroi(flag, e, str);
	else if (flag.width > e && flag.minus != 0 && flag.width > flag.prec)
		compt = ft_print_space_plus_minusnormv2(flag, e, str, "cinq");
	else if ((flag.prec >= flag.width) && (flag.prec > e - 1))
		compt = ft_print_space_plus_minusnormv2(flag, e, str, "six");
	return (compt);
}
