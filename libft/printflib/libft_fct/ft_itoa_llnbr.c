/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:45:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_nf(long long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static int		taille(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa_llnbr(long long n)
{
	int			neg;
	int			len;
	char		*str;
	long long	i;
	long long	j;

	j = -9223372036854775807;
	i = n;
	if (i == j - 1)
		return (ft_strdup("-9223372036854775808"));
	neg = 0;
	ft_nf(&n, &neg);
	len = taille(n) + neg;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
