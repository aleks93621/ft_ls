/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:14:03 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_lst(t_lst *lst, t_rep *rep)
{
	t_lst *tmp;
	t_rep *tmp2;

	lst = rep->debut;
	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
			if (tmp->path)
				ft_strdel(&(tmp)->path);
			free(tmp);
		}
	}
	tmp2 = rep;
	free(tmp2);
}
