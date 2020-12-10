/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_call_print_dir(DIR *dp, t_options *op, t_lst *lst)
{
	struct stat		buf;

	while (lst != NULL)
	{
		lstat(lst->path, &buf);
		if ((dp = opendir(lst->path)) != NULL)
		{
			op->aff++;
			if (op->l == 0 || !S_ISLNK(buf.st_mode))
				op->err = print_dir(lst->path, *op, dp);
			closedir(dp);
			errno = 0;
		}
		if (errno == 13 && (lst->path)[0] != '.')
			no_right(lst->path, *&op);
		lst = lst->next;
	}
}

int				ft_ls(t_options op)
{
	t_lst			*lst;
	t_rep			*rep;
	DIR				*dp;

	lst = NULL;
	rep = NULL;
	dp = NULL;
	if ((rep = (t_rep*)malloc(sizeof(*rep))) == NULL)
		return (-1);
	init_rep(rep);
	lst_init(rep, lst, &op);
	ft_sort(lst, rep, op);
	op.aff = print_files(&op, lst, rep);
	lst = rep->debut;
	ft_call_print_dir(dp, &op, lst);
	free_lst(lst, rep);
	return (op.err);
}

int				main(int argc, char **argv)
{
	t_options	opt;
	char		**str;

	opt = init_options(argc, argv);
	fill_options(&opt, 1);
	opt.err = check_errors(opt);
	if (argc == opt.i)
	{
		if ((str = (char**)malloc(sizeof(char*) * 2)) == NULL)
			exit(2);
		str[0] = ".";
		str[1] = NULL;
		opt.i = 0;
		opt.point = 1;
		opt.argv = str;
	}
	opt.err = ft_ls(opt);
	if (opt.point == 1)
	{
		free(str);
		str = NULL;
	}
	if (opt.err > 0)
		exit(2);
	return (0);
}
