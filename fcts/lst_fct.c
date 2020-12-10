/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:19:18 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				init_rep(t_rep *init)
{
	init->debut = NULL;
	init->fin = NULL;
	init->taille = 0;
}

t_lst				*createlist(char *str, t_rep *liste)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	if (new == NULL)
		new->path = NULL;
	else
	{
		if ((new->path = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1)))
				== NULL)
			return (NULL);
		ft_strcpy(new->path, str);
	}
	new->next = NULL;
	liste->debut = new;
	liste->fin = new;
	liste->taille++;
	return (new);
}

void				lst_add_end(t_rep *liste, t_lst *courant, char *str)
{
	t_lst *new;

	if ((new = (t_lst*)malloc(sizeof(*new))) == NULL)
		return ;
	if ((new->path = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1)))
			== NULL)
		return ;
	ft_strcpy(new->path, str);
	courant->next = new;
	new->next = NULL;
	liste->fin = new;
	liste->taille++;
}

void				lst_init(t_rep *repere, t_lst *lst, t_options *op)
{
	struct stat		stats;
	struct stat		statsb;

	while ((*op).i < (*op).argc)
	{
		if ((*op).point != 1)
			(*op).rac++;
		lstat((*op).argv[(*op).i], &statsb);
		if (lstat((*op).argv[(*op).i], &stats) != -1 || S_ISLNK(statsb.st_mode))
		{
			if (repere->taille == 0)
				lst = createlist((*op).argv[(*op).i], repere);
			else
			{
				lst_add_end(repere, lst, (*op).argv[(*op).i]);
				lst = lst->next;
			}
		}
		(*op).i++;
	}
}
