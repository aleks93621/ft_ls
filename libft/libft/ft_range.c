/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:26:07 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *tableau;

	i = 0;
	if (min >= max)
		return (0);
	else
	{
		tableau = (int*)malloc(sizeof(int*) * (max - min));
		while (min != max)
		{
			tableau[i] = min;
			i++;
			min++;
		}
	}
	return (tableau);
}
