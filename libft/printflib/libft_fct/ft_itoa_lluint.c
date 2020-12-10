/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lluint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:13:50 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_lluint(unsigned long long n)
{
	char				*d;
	unsigned long long	i;
	int					longu;

	longu = 2;
	i = n;
	while (i /= 10)
		longu++;
	if (!(d = (char*)malloc(sizeof(char) * longu)))
		return (NULL);
	d[--longu] = '\0';
	while (longu--)
	{
		d[longu] = n % 10 + '0';
		n = n / 10;
	}
	return (d);
}
