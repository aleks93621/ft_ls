/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binaire.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:20:18 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_zero_spacev5(t_flags flag, int a)
{
	int i;

	i = 0;
	while (i < flag.width - a)
	{
		if (flag.zero != 0 && flag.minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

int			ft_print_binaire(t_flags flag, va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	if (flag.size == '.')
	{
		str = ft_itoabasel(va_arg(ap, unsigned long long), 2);
		count = ft_strlen(str);
		if (flag.width > 0 && flag.minus == 0)
			count += write_zero_spacev5(flag, ft_strlen(str));
		ft_putstr(str);
		if (flag.width > 0 && flag.minus == 1)
			count += write_zero_spacev5(flag, ft_strlen(str));
		free(str);
	}
	return (count);
}
