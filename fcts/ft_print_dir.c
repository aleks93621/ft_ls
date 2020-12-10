/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:05:02 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_print_errno(t_options **op, t_lst *tmp)
{
	int i;

	i = 0;
	if (tmp->path[0] == '/' && tmp->path[1] == '/' && tmp->path[2] != '/')
		i = 1;
	if ((*op)->aff > 1)
		ft_putchar('\n');
	((*op)->aff)++;
	((*op)->err)++;
	ft_printf("%s:\n", tmp->path + i);
	no_right(tmp->path, *op);
}

void	ls_rec(t_lst *tmp, t_options *op, DIR *dp, char *path)
{
	struct stat	stats;

	while (tmp != NULL && op->rr == 1)
	{
		lstat(tmp->path, &stats);
		errno = 0;
		if ((dp = opendir(tmp->path)) != NULL)
		{
			if (!S_ISLNK(stats.st_mode) && ((ft_strcmp(tmp->path +
						ft_strlen(path), ".")) != 0) && ((ft_strcmp(tmp->path
							+ ft_strlen(path), "..")) != 0))
			{
				op->aff++;
				print_dir(tmp->path, *op, dp);
			}
			closedir(dp);
		}
		if (errno == 13)
			ls_print_errno(&op, tmp);
		tmp = tmp->next;
	}
}

t_rep	*init_t_rep(t_rep **tmprep, t_options *op, char *path)
{
	t_rep	*rep;
	int		i;

	i = 0;
	if (path[0] == '/' && path[1] == '/' && path[2] != '/')
		i = 1;
	if (op->aff > 1)
		ft_putchar('\n');
	if ((op->rac++) > 1)
		ft_printf("%s:\n", path + i);
	if ((rep = (t_rep*)malloc(sizeof(*rep))) == NULL)
		return (NULL);
	if ((*tmprep = (t_rep*)malloc(sizeof(**tmprep))) == NULL)
		return (NULL);
	init_rep(*tmprep);
	init_rep(rep);
	return (rep);
}

int		print_dir(char *path, t_options op, DIR *dp)
{
	t_lst		*lst;
	t_rep		*rep;
	t_rep		*tmprep;
	t_lst		*tmp;

	tmprep = NULL;
	rep = init_t_rep(&tmprep, &op, path);
	path = ft_strjoin(path, "/");
	lst = fill_doss(rep, op, dp);
	lst = rep->debut;
	tmp = fill_doss_bis(tmprep, path, lst);
	tmp = tmprep->debut;
	ft_sort(tmp, tmprep, op);
	tmp = tmprep->debut;
	(op.rac)++;
	print_l(tmp, op, path);
	tmp = tmprep->debut;
	ls_rec(tmp, &op, dp, path);
	ft_strdel(&path);
	free_lst(tmp, tmprep);
	free_lst(lst, rep);
	return (op.err);
}
