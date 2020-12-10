/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:56:13 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_nf(short *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa_hnbr(short n)
{
	char	*d;
	int		i;
	int		negative;
	int		longu;

	longu = 2;
	negative = 0;
	i = n;
	if (n == -32768)
		return (ft_strdup("-32768"));
	ft_nf(&n, &negative);
	while (i /= 10)
		longu++;
	longu = longu + negative;
	if (!(d = (char*)malloc(sizeof(char) * longu)))
		return (NULL);
	d[--longu] = '\0';
	while (longu--)
	{
		d[longu] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		d[0] = '-';
	return (d);
}
