/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_plus_minus.c                        :+:      :+:    :+:   */
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
	if (flag.zero != 0)
		ft_putchar('-');
	while (tmp > e)
	{
		if (flag.zero != 0)
			ft_putchar('0');
		else if (flag.minus == 0)
			ft_putchar(' ');
		tmp--;
	}
	if (flag.zero == 0)
		ft_putchar('-');
	ft_putstr_n(str, 1);
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
	ft_putchar('-');
	while (tmp2 - (e - 1) > 0)
	{
		ft_putchar('0');
		tmp2--;
	}
	ft_putstr_n(str, 1);
	return (tmpj + flag.prec + 1);
}

static int		ft_normedeu(t_flags flag, int j, int e, char *str)
{
	int tmp2;
	int tmpj;

	tmp2 = flag.prec;
	tmpj = j;
	ft_putchar('-');
	while (tmp2 - (e - 1) > 0)
	{
		ft_putchar('0');
		tmp2--;
	}
	ft_putstr_n(str, 1);
	while (j--)
		ft_putchar(' ');
	return (tmpj + flag.prec + 1);
}

static int		flag_longu(t_flags flag)
{
	int i;

	i = 0;
	if ((flag.width != -1) && (flag.width > flag.prec) && flag.prec != -1 &&
			flag.prec != 0)
		i = flag.width - (flag.prec + 1);
	return (i);
}

int				ft_print_space_plus_minus(t_flags flag, int e, char *str)
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
		compt = ft_print_space_plus_minusnorm(flag, e, str, "trois");
	else if (flag.width > e && flag.minus == 0 && flag.width > flag.prec)
		compt = ft_normetroi(flag, e, str);
	else if (flag.width > e && flag.minus != 0 && flag.width > flag.prec)
		compt = ft_print_space_plus_minusnorm(flag, e, str, "cinq");
	else if ((flag.prec >= flag.width) && (flag.prec > e - 1))
		compt = ft_print_space_plus_minusnorm(flag, e, str, "six");
	return (compt);
}
