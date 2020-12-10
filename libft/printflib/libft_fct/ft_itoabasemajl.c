/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasemajl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:07:58 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	compte(unsigned long long nbr, int base)
{
	unsigned long long ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoabasemajl(unsigned long long nbr, int base)
{
	char				*retour;
	unsigned long long	nb;
	unsigned long long	i;
	char				tab[17];

	if (nbr == 0)
		return (ft_strdup("0"));
	ft_strcpy(tab, "0123456789ABCDEF");
	nb = compte(nbr, base);
	retour = ft_strnew(nb + 1);
	i = 1;
	while (nbr != 0)
	{
		retour[nb - i] = tab[nbr % base];
		nbr /= base;
		i++;
	}
	retour[nb] = '\0';
	return (retour);
}
