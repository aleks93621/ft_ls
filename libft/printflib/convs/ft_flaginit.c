/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaginit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:00:27 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_flaginit(void)
{
	t_flags	flag;

	flag.point = 0;
	flag.hash = 0;
	flag.zero = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.width = -1;
	flag.prec = -1;
	flag.size = '.';
	flag.conv = '#';
	return (flag);
}
