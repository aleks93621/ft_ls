/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_doss_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:52:19 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_files(t_options *op, t_lst *list, t_rep *rep)
{
	int		a;

	list = rep->debut;
	a = 0;
	a = print_file_l(list, *&op);
	if ((*op).l == 0)
		return (a);
	return (a);
}

t_lst	*fill_doss(t_rep *repere, t_options op, DIR *dp)
{
	struct dirent	*dirp;
	t_lst			*liste;
	struct stat		stats;

	while ((dirp = readdir(dp)) != NULL)
	{
		stat(dirp->d_name, &stats);
		if ((dirp->d_name)[0] != '.' || op.a == 1)
		{
			if (repere->taille == 0)
				liste = createlist(dirp->d_name, repere);
			else
			{
				lst_add_end(repere, liste, dirp->d_name);
				liste = liste->next;
			}
		}
	}
	return (liste);
}

t_lst	*createlist_bis(char *str, t_rep *liste, char *path)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	if (new == NULL)
		new->path = NULL;
	else
		new->path = ft_strjoin(path, str);
	new->next = NULL;
	liste->debut = new;
	liste->fin = new;
	liste->taille++;
	return (new);
}

void	lst_add_end_bis(t_rep *liste, t_lst *courant, char *str, char *path)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(*new))) == NULL)
		return ;
	new->path = ft_strjoin(path, str);
	courant->next = new;
	new->next = NULL;
	liste->fin = new;
	liste->taille++;
}

t_lst	*fill_doss_bis(t_rep *repere, char *str, t_lst *lst)
{
	t_lst	*liste;

	while (lst)
	{
		if (repere->taille == 0)
			liste = createlist_bis(lst->path, repere, str);
		else
		{
			lst_add_end_bis(repere, liste, lst->path, str);
			liste = liste->next;
		}
		lst = lst->next;
	}
	return (liste);
}
