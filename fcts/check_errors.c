/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int			nb_errors(t_options opt)
{
	int				i;
	struct stat		stats;

	i = 0;
	while (opt.i < opt.argc)
	{
		if (stat((opt.argv[opt.i]), &stats) == -1)
			i++;
		(opt.i)++;
	}
	return (i);
}

static void			print_error(t_lst *errors, t_rep *rep)
{
	errors = rep->debut;
	while (errors != NULL)
	{
		bad_dir_err(errors->path);
		errors = errors->next;
	}
	free_lst(errors, rep);
}

static t_lst		*fill_errors(t_options *opt, t_rep *rep)
{
	t_lst			*errors;
	struct stat		stats;

	if ((errors = (t_lst*)malloc(sizeof(*errors))) == NULL)
		return (NULL);
	while ((*opt).i < (*opt).argc)
	{
		lstat((*opt).argv[(*opt).i], &stats);
		if (S_ISLNK(stats.st_mode))
			ft_printf("\0");
		else if (stat(((*opt).argv[(*opt).i]), &stats) == -1 &&
			rep->taille == 0)
		{
			errors = createlist(((*opt).argv[(*opt).i]), rep);
			((*opt).err) += 1;
		}
		else if (stat(((*opt).argv[(*opt).i]), &stats) == -1 && rep->taille > 0)
		{
			lst_add_end(rep, errors, ((*opt).argv[(*opt).i]));
			errors = errors->next;
			((*opt).err) += 1;
		}
		((*opt).i)++;
	}
	return (errors);
}

int					check_errors(t_options opt)
{
	t_rep			*rep;
	t_lst			*errors;

	if (nb_errors(opt) == 0)
		return (0);
	if ((rep = (t_rep*)malloc(sizeof(*rep))) == NULL)
		return (-1);
	init_rep(rep);
	errors = fill_errors(&opt, rep);
	errors = sort_lst2(errors, rep);
	print_error(errors, rep);
	return (opt.err);
}
