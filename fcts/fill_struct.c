/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:05:09 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_options			init_options(int argc, char **argv)
{
	t_options options;

	options.i = 0;
	options.a = 0;
	options.l = 0;
	options.r = 0;
	options.rr = 0;
	options.t = 0;
	options.err = 0;
	options.aff = 0;
	options.rac = 0;
	options.g = 0;
	options.gg = 0;
	options.o = 0;
	options.p = 0;
	options.argc = argc;
	options.argv = argv;
	options.un = 0;
	options.point = 0;
	options.tiret = 0;
	options.ff = 0;
	return (options);
}

void				ft_fill_bis_bis(char c, t_options *opt)
{
	if (c == 'p')
		opt->p = 1;
	else if (c == 'R')
		opt->rr = 1;
	else if (c == 't')
		opt->t = 1;
	else if (c == 'G')
		opt->gg = 1;
	else if (c == 'o')
	{
		opt->l = 1;
		opt->o = 1;
	}
	else if (c == 'g')
	{
		opt->l = 1;
		opt->g = 1;
	}
	else if (c == '1')
	{
		opt->un = 1;
		opt->l = 0;
	}
}

void				ft_fill_bis(char c, t_options *opt)
{
	if (c == 'a')
		opt->a = 1;
	else if (c == 'l')
		opt->l = 1;
	else if (c == 'r')
		opt->r = 1;
	else if (c == 'F')
	{
		opt->p = 0;
		opt->ff = 1;
	}
	else
		ft_fill_bis_bis(c, opt);
}

int					ft_une_de_ceslettres(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't' || c == 'o'
			|| c == 'g' || c == '1' || c == 'F' || c == 'p' || c == 'G')
		return (1);
	return (0);
}

void				fill_options(t_options *opt, int j)
{
	opt->i = 1;
	while (opt->argc > opt->i && (opt->argv[opt->i][0]) == '-' &&
			(opt->argv[opt->i][1]) != '\0')
	{
		j = 1;
		while ((opt->argv[opt->i][j]) != '\0')
		{
			if (opt->argv[opt->i][j] == '-')
			{
				if (opt->argv[opt->i][j - 1] != '-' || opt->argv[opt->i][j + 1]
						!= '\0')
					bad_option_err(opt->argv[opt->i][j]);
				opt->tiret = 1;
			}
			else if (ft_une_de_ceslettres(opt->argv[opt->i][j]) == 1)
				ft_fill_bis(opt->argv[opt->i][j], opt);
			else
				bad_option_err((opt->argv[opt->i][j]));
			j++;
		}
		opt->i++;
		if (opt->tiret == 1)
			break ;
	}
}
