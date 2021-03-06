/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:35:58 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 0)
		return (0);
	while (i * i < nb)
		i++;
	if ((nb % i) == 0 && (i * i) == nb)
		return (i);
	else
		return (0);
}
