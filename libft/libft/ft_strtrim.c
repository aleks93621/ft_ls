/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:25:20 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char				*returp(char *p)
{
	while (*p == ' ' || *p == '\n' || *p == '\t')
		p--;
	return (p);
}

static const char		*returs(char const *s)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	return (s);
}

char					*ft_strtrim(char const *s)
{
	char	*d;
	char	*t;
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	t = ft_strnew(ft_strlen(s) + 1);
	if (t == NULL)
		return (NULL);
	p = (char*)s + (ft_strlen(s) - 1);
	i = 0;
	s = returs(s);
	p = returp(p);
	while (s <= p)
	{
		t[i] = *s;
		i++;
		s++;
	}
	t[i] = '\0';
	d = ft_strnew(ft_strlen(t));
	ft_strcpy(d, t);
	return (d);
}
