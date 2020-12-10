/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hhnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:23:53 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_nf(signed char *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa_hhnbr(signed char n)
{
	char	*d;
	int		i;
	int		negative;
	int		longu;

	longu = 2;
	negative = 0;
	i = n;
	if (n == -128)
		return (ft_strdup("-128"));
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
