/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:41:32 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		longu;
	char	*ok;

	ok = (char*)s;
	longu = ft_strlen(ok);
	while (longu > 0)
	{
		if (s[longu] == (char)c)
			return ((char*)s + longu);
		longu--;
	}
	if (s[longu] == (char)c)
		return ((char*)s + longu);
	else
		return (NULL);
}
