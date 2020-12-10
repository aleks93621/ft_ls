/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:23:33 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_checker_x(t_flags flag, va_list ap)
{
	if (flag.size == 'H' && flag.conv != 'X')
		return (ft_itoabasehh((unsigned char)va_arg(ap, unsigned int), 16));
	else if (flag.size == 'h' && flag.conv != 'X')
		return (ft_itoabaseh((unsigned short)va_arg(ap, unsigned int), 16));
	else if (flag.size == 'l' && flag.conv != 'X')
		return (ft_itoabasel(va_arg(ap, unsigned long), 16));
	else if (flag.size == 'L' && flag.conv != 'X')
		return (ft_itoabasel(va_arg(ap, unsigned long long), 16));
	else if (flag.size == 'j' && flag.conv != 'X')
		return (ft_itoabasel(va_arg(ap, uintmax_t), 16));
	else if (flag.size == 'z' && flag.conv != 'X')
		return (ft_itoabasel(va_arg(ap, size_t), 16));
	else if (flag.size == '.' && flag.conv != 'X')
		return (ft_itoabase(va_arg(ap, unsigned int), 16));
	else if (flag.conv == 'X')
		return (ft_checker_x_maj(flag, ap));
	else
		return (NULL);
}
