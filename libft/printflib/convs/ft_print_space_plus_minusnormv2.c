/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_plus_minusnormv2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:28:48 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_normesix(t_flags flag, int e, char *str)
{
	int tmp2;

	tmp2 = flag.prec;
	if (flag.plus != 0)
	{
		e++;
		ft_putchar('+');
	}
	else if (flag.space != 0 && flag.plus == 0)
	{
		e++;
		ft_putchar(' ');
	}
	while ((tmp2-- - e) > 0)
		ft_putchar('0');
	ft_putstr(str);
	return (flag.prec);
}

static int		ft_normecinq(t_flags flag, int e, char *str)
{
	int tmp;

	tmp = flag.width;
	if (flag.plus != 0)
	{
		e++;
		ft_putchar('+');
	}
	else if (flag.space != 0 && flag.plus == 0)
	{
		e++;
		ft_putchar(' ');
	}
	ft_putstr(str);
	while (tmp > e)
	{
		ft_putchar(' ');
		tmp--;
	}
	return (flag.width);
}

static int		ft_normequatr(t_flags flag, int e, char *str)
{
	int tmp;

	tmp = flag.width;
	if (flag.plus != 0 || flag.space != 0)
		tmp--;
	while (tmp > e)
	{
		ft_putchar(' ');
		tmp--;
	}
	if (flag.plus != 0)
		ft_putchar('+');
	else if (flag.space != 0 && flag.plus == 0)
		ft_putchar(' ');
	ft_putstr(str);
	return (flag.width);
}

int				ft_print_space_plus_minusnormv2(t_flags flag, int e, char *str,
		char *ok)
{
	int compt;

	compt = 0;
	if (ft_strcmp(ok, "trois") == 0)
		compt = ft_normequatr(flag, e, str);
	else if (ft_strcmp(ok, "cinq") == 0)
		compt = ft_normecinq(flag, e, str);
	else if (ft_strcmp(ok, "six") == 0)
		compt = ft_normesix(flag, e, str);
	return (compt);
}
