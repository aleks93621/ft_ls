/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:58:23 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	d = (char*)malloc((len + 1) * sizeof(*s));
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[start];
		start++;
		i++;
	}
	d[i] = '\0';
	return (d);
}
