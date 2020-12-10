/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 03:28:09 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_width		init_wid(void)
{
	t_width options;

	options.blk = 0;
	options.lks = 0;
	options.own = 0;
	options.grp = 0;
	options.maj = 0;
	options.byt = 0;
	options.acl = 2;
	options.err = 0;
	return (options);
}

static int			fill_width(struct stat buf, t_width *wid)
{
	struct passwd	*pas;
	struct group	*gid;

	if ((pas = getpwuid(buf.st_uid)) == NULL)
		return (-1);
	gid = getgrgid(buf.st_gid);
	wid->blk += buf.st_blocks;
	if (nbr_val((uintmax_t)buf.st_nlink) > wid->lks)
		wid->lks = nbr_val((uintmax_t)buf.st_nlink);
	if ((nbr_val((uintmax_t)major(buf.st_rdev)) > wid->maj) &&
		(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)))
		wid->maj = nbr_val((uintmax_t)major(buf.st_rdev));
	if (nbr_val((uintmax_t)buf.st_size) > wid->byt)
		wid->byt = nbr_val((uintmax_t)buf.st_size);
	if (nbr_val((uintmax_t)minor(buf.st_rdev)) > wid->byt)
		wid->byt = nbr_val((uintmax_t)minor(buf.st_rdev));
	if (ft_strlen(pas->pw_name) > wid->own)
		wid->own = ft_strlen(pas->pw_name);
	if (ft_strlen(gid->gr_name) > wid->grp)
		wid->grp = ft_strlen(gid->gr_name);
	return (0);
}

t_width				fill_wid(t_lst *list)
{
	t_width		wid;
	struct stat	buf;

	wid = init_wid();
	while (list)
	{
		lstat(list->path, &buf);
		wid.err = fill_width(buf, &wid);
		list = list->next;
	}
	return (wid);
}
