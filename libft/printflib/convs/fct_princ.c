/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_princ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:41:36 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_width_or_preci(const char *str, int *k)
{
	char	*nb;
	int		j;
	int		i;

	i = *k;
	j = 0;
	nb = NULL;
	while (str[i] > 47 && str[i] < 58)
	{
		j++;
		i++;
	}
	nb = ft_strsub(str, i - j, j + 1);
	i--;
	*k = i;
	return (nb);
}

static void			ft_wop(t_flags *flag, const char *str, int *k)
{
	int		i;
	char	*nb;

	i = *k;
	if (str[i] == '.')
	{
		(*flag).point = 1;
		i++;
		nb = ft_width_or_preci(str, &i);
		if (nb != NULL)
			(*flag).prec = ft_atoi(nb);
		free(nb);
	}
	else if (str[i] > 47 && str[i] < 58)
	{
		nb = ft_width_or_preci(str, &i);
		if (nb != NULL)
			(*flag).width = ft_atoi(nb);
		free(nb);
	}
	*k = i;
}

static void			ft_char(t_flags *flag, const char *str, int *k)
{
	int	i;

	i = *k;
	if ((*flag).size == '.' || str[i] == 'l')
	{
		if (str[i] == 'h' || str[i] == 'l')
		{
			if (str[i + 1] == str[i])
			{
				(*flag).size = str[i] - 32;
				i++;
			}
			else
				(*flag).size = str[i];
			i++;
		}
		else if (str[i] == 'j' || str[i] == 'z')
		{
			(*flag).size = str[i];
			i++;
		}
		*k = i - 1;
	}
}

static void			ft_rempflag(const char *str, t_flags *flag, int *i)
{
	while (ft_isparam(str[*i]) == 1)
	{
		if (str[*i] == '-')
			(*flag).minus = 1;
		else if (str[*i] == '+')
			(*flag).plus = 1;
		else if (str[*i] == ' ')
			(*flag).space = 1;
		else if (str[*i] == '0')
			(*flag).zero = 1;
		else if (str[*i] == '#')
			(*flag).hash = 1;
		else if (str[*i] == '.' || (str[*i] > 47 && str[*i] < 58))
			ft_wop(*&flag, str, *&i);
		if (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j' || str[*i]
				== 'z')
			ft_char(*&flag, str, *&i);
		(*i)++;
	}
}

t_flags				ft_fillflag(const char *str, int *k)
{
	t_flags		flag;
	int			i;

	i = *k + 1;
	flag = ft_flaginit();
	ft_rempflag(str, &flag, &i);
	if (str[i] != '\0')
		flag.conv = str[i];
	*k = i;
	return (flag);
}
