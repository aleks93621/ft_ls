/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_unic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:06:02 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_test(const char *str, int j, va_list ap, t_flags flag)
{
	va_list	aq;
	int		i;

	i = j;
	while (str[i] != '\0' && str[i - 1] != '%')
	{
		if (str[i] == '%')
		{
			va_copy(aq, ap);
			flag = ft_fillflag(str, &i);
			if ((flag.conv == 'C' || (flag.size == 'l' && flag.conv == 'c')) &&
					checker_wchar(va_arg(aq, wchar_t)) == -1)
				return (-1);
			else if (flag.conv == 'S' &&
					checker_wstr(va_arg(aq, wchar_t*)) == -1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
