/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			sort_lst(t_lst *lst, t_rep *rep, t_options op)
{
	t_lst	*tmp;
	char	*tmpo;

	lst = rep->debut;
	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if ((ft_strcmp(lst->path, tmp->path) > 0 && op.r == 0)
					|| (ft_strcmp(lst->path, tmp->path) < 0 && op.r == 1))
			{
				tmpo = lst->path;
				lst->path = tmp->path;
				tmp->path = tmpo;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void			time_return_val(struct stat *stats, t_options op, t_lst **list,
		t_lst **tmp)
{
	struct stat		stats2;
	char			*tmpo;

	lstat((*tmp)->path, &stats2);
	if (((*stats).st_mtime < stats2.st_mtime && op.r == 0) ||
			((*stats).st_mtime > stats2.st_mtime && op.r == 1) ||
			((*stats).st_mtime == stats2.st_mtime && ft_strcmp((*list)->path
				, (*tmp)->path) > 0 && op.r == 0) || ((*stats).st_mtime ==
			stats2.st_mtime && ft_strcmp((*list)->path, (*tmp)->path)
			< 0 && op.r == 1))
	{
		tmpo = (*list)->path;
		(*list)->path = (*tmp)->path;
		(*tmp)->path = tmpo;
		lstat((*list)->path, stats);
	}
}

void			sort_t(t_lst *list, t_rep *rep, t_options op)
{
	struct stat		stats;
	t_lst			*tmp;

	list = rep->debut;
	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		lstat(list->path, &stats);
		while (tmp)
		{
			time_return_val(&stats, op, &list, &tmp);
			tmp = tmp->next;
		}
		list = list->next;
	}
}

void			ft_sort(t_lst *list, t_rep *rep, t_options op)
{
	sort_lst(list, rep, op);
	if (op.t == 1)
		sort_t(list, rep, op);
}
