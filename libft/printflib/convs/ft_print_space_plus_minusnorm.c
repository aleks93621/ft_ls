/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space_plus_minusnorm.c                    :+:      :+:    :+:   */
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
	ft_putchar('-');
	while (tmp2 - (e - 1) > 0)
	{
		ft_putchar('0');
		tmp2--;
	}
	ft_putstr_n(str, 1);
	return (flag.prec + 1);
}

static int		ft_normecinq(t_flags flag, int e, char *str)
{
	int tmp;

	tmp = flag.width;
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
	while (tmp > e)
	{
		ft_putchar(' ');
		tmp--;
	}
	ft_putstr(str);
	return (flag.width);
}

int				ft_print_space_plus_minusnorm(t_flags flag, int e, char *str,
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
