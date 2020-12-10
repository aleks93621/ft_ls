/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lst			*sort_lst2(t_lst *errors, t_rep *rep)
{
	t_lst	*tmp;
	char	*tmpo;

	errors = rep->debut;
	if (!errors)
		return (errors);
	while (errors)
	{
		tmp = errors->next;
		while (tmp)
		{
			if (ft_strcmp(errors->path, tmp->path) > 0)
			{
				tmpo = errors->path;
				errors->path = tmp->path;
				tmp->path = tmpo;
			}
			tmp = tmp->next;
		}
		errors = errors->next;
	}
	return (errors);
}
