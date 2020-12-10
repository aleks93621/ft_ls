/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:19:36 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printarg(t_flags flag, va_list ap, unsigned int j)
{
	unsigned int		e;

	e = 0;
	if (flag.conv == 'c' || flag.conv == 'C')
		e = ft_printchar(flag, ap);
	else if (flag.conv == 's' || flag.conv == 'S')
		e = ft_printstr(flag, ap);
	else if (flag.conv == 'i' || flag.conv == 'd' || flag.conv == 'D')
		e = ft_printnbr(flag, ap);
	else if (flag.conv == 'u' || flag.conv == 'U')
		e = ft_printunsint(flag, ap);
	else if (flag.conv == 'x' || flag.conv == 'X')
		e = ft_printhex(flag, ap);
	else if (flag.conv == 'o' || flag.conv == 'O')
		e = ft_printoct(flag, ap);
	else if (flag.conv == 'p')
		e = ft_printvoid_hex(flag, ap);
	else if (flag.conv == 'b')
		e = ft_print_binaire(flag, ap);
	else if (flag.conv == 'n')
		e = ft_bonusn(ap, (int)j);
	if (!ap)
		return (-1);
	return (e);
}

static int	ft_printfbis(const char *format, int i, va_list ap, int *a)
{
	t_flags				flag;
	static unsigned int	e;

	e = 0;
	while (format[i] != '\0' && (*a = ft_test(format, i, ap, flag)) == 0)
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			e++;
		}
		else
		{
			flag = ft_fillflag(format, &i);
			if ((ftc(format[i]) == 0 || flag.conv == '%') && flag.conv != '#')
				e += ft_print_isnoparam(flag);
			else if (flag.conv != '#')
				e += ft_printarg(flag, ap, e);
			else
				break ;
		}
		i++;
	}
	return (e);
}

int			ft_printf(const char *format, ...)
{
	va_list				ap;
	int					i;
	unsigned int		e;
	int					a;

	a = 0;
	i = 0;
	va_start(ap, format);
	e = ft_printfbis(format, i, ap, &a);
	va_end(ap);
	if (a == -1)
		return (a);
	return (e);
}
