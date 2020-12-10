/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwtchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:41:55 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F && MB_CUR_MAX >= 1)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0xFF && MB_CUR_MAX == 1)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF && MB_CUR_MAX >= 1)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else
		ft_putchar_fd(chr, fd);
}
