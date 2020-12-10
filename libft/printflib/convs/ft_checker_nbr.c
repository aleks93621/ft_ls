/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:23:33 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_checker_size_nbr(t_flags flag, va_list ap)
{
	if (flag.conv == 'D')
		return (ft_itoa_lnbr(va_arg(ap, long)));
	else if (flag.size == 'H')
		return (ft_itoa_hhnbr((signed char)va_arg(ap, int)));
	else if (flag.size == 'h')
		return (ft_itoa_hnbr((short)va_arg(ap, int)));
	else if (flag.size == 'l')
		return (ft_itoa_lnbr(va_arg(ap, long)));
	else if (flag.size == 'L')
		return (ft_itoa_llnbr(va_arg(ap, long long)));
	else if (flag.size == 'j')
		return (ft_itoa_llnbr(va_arg(ap, intmax_t)));
	else if (flag.size == 'z')
		return (ft_itoa_llnbr(va_arg(ap, size_t)));
	else if (flag.size == '.')
		return (ft_itoa(va_arg(ap, int)));
	else
		return (NULL);
}
