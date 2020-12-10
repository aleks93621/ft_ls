/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_attrib(char *path, t_width *wid)
{
	int		i;
	acl_t	acl;

	acl = NULL;
	i = 0;
	i = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (i > 0)
	{
		ft_printf("@");
		((*wid).acl) = 1;
	}
	else if (acl_get_file(path, ACL_TYPE_EXTENDED))
	{
		acl_free((void*)acl);
		ft_putchar('+');
		((*wid).acl) = 1;
	}
}

void		print_color(char *str, t_options op, int i)
{
	struct stat	buf;

	lstat(str, &buf);
	if (op.gg == 1 && S_ISLNK(buf.st_mode))
		ft_printf("%s%s%s", CMAG, str + i, CNORM);
	else if (op.gg == 1 && S_ISDIR(buf.st_mode))
		ft_printf("%s%s%s", CCYA, str + i, CNORM);
	else if (op.gg == 1 && S_ISSOCK(buf.st_mode))
		ft_printf("%s%s%s", CVER, str + i, CNORM);
	else if (op.gg == 1 && S_ISFIFO(buf.st_mode))
		ft_printf("%s%s%s", CJAU, str + i, CNORM);
	else if ((S_IXUSR & buf.st_mode || S_IXGRP & buf.st_mode || S_IXOTH &
				buf.st_mode) && op.gg == 1)
		ft_printf("%s%s%s", CROU, str + i, CNORM);
	else
		ft_printf("%s", str + i);
}

void		print_lnl(char *path, t_options *op, t_width wid, t_lst *list)
{
	char			*lnk;
	struct stat		buf;

	lstat(list->path, &buf);
	print_aut(buf);
	print_attrib(list->path, &wid);
	print_names(buf, *op, wid);
	if (wid.acl == 1)
		wid.acl = 2;
	print_color(list->path, *op, ft_strlen(path));
	if (op->ff == 1 || op->p == 1)
		print_ff(list->path, *op);
	if (S_ISLNK(buf.st_mode))
	{
		if ((lnk = malloc(PATH_MAX)) == NULL)
			return ;
		lnk[readlink(list->path, lnk, PATH_MAX)] = '\0';
		ft_printf(" -> %s", lnk);
		ft_strdel(&lnk);
	}
	ft_putchar('\n');
}

void		print_l(t_lst *list, t_options op, char *path)
{
	t_width			wid;
	struct passwd	*pas;
	struct stat		buf;

	op.a = 0;
	if (op.l)
		wid = fill_wid(list);
	if (list != NULL && op.l == 1 && wid.err == 0)
		ft_printf("total %zd\n", wid.blk);
	while (list)
	{
		lstat(list->path, &buf);
		if ((op.l == 1) && (pas = getpwuid(buf.st_uid)) != NULL)
			print_lnl(path, &op, wid, list);
		else if ((pas = getpwuid(buf.st_uid)) != NULL)
		{
			print_color(list->path, op, ft_strlen(path));
			if (op.ff == 1 || op.p == 1)
				print_ff(list->path, op);
			ft_putchar('\n');
		}
		list = list->next;
	}
}
