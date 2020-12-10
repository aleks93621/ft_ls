/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasemajh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:07:58 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	compte(unsigned short nbr, int base)
{
	unsigned short ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoabasemajh(unsigned short nbr, int base)
{
	char			*retour;
	unsigned short	nb;
	unsigned short	i;
	char			tab[17];

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
