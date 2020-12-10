/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_aut(struct stat buf)
{
	ft_printf((S_ISDIR(buf.st_mode)) ? "d" : "");
	ft_printf((S_ISFIFO(buf.st_mode)) ? "p" : "");
	ft_printf((S_ISCHR(buf.st_mode)) ? "c" : "");
	ft_printf((S_ISBLK(buf.st_mode)) ? "b" : "");
	ft_printf((S_ISSOCK(buf.st_mode)) ? "s" : "");
	ft_printf((S_ISLNK(buf.st_mode)) ? "l" : "");
	ft_printf((S_ISREG(buf.st_mode)) ? "-" : "");
	ft_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
	if (buf.st_mode & S_ISUID)
		ft_printf("%c", 83 + 32 * ((buf.st_mode & S_IRWXU) ? 1 : 0));
	else
		ft_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
	if (buf.st_mode & S_ISGID)
		ft_printf("%c", 83 + 32 * ((buf.st_mode & S_IRWXG) ? 1 : 0));
	else
		ft_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
	if (buf.st_mode & S_ISVTX)
		ft_printf("%c", 84 + 32 * ((buf.st_mode & S_IRWXO) ? 1 : 0));
	else
		ft_printf((buf.st_mode & S_IXOTH) ? "x" : "-");
}

void	print_ff(char *path, t_options op)
{
	struct stat buf;

	lstat(path, &buf);
	if (S_ISLNK(buf.st_mode) && op.p == 0)
		ft_putchar('@');
	else if (S_ISDIR(buf.st_mode))
		ft_putchar('/');
	else if (S_ISFIFO(buf.st_mode) && op.p == 0)
		ft_putchar('|');
	else if (S_ISSOCK(buf.st_mode) && op.p == 0)
		ft_putchar('=');
	else if ((S_IXUSR & buf.st_mode || S_IXGRP & buf.st_mode || S_IXOTH &
			buf.st_mode) && op.p == 0)
		ft_putchar('*');
}

void	print_lnk(struct stat buf, t_options *op, t_width wid, t_lst *list)
{
	char			*lnk;

	lstat(list->path, &buf);
	print_aut(buf);
	print_attrib(list->path, &wid);
	print_names(buf, *op, wid);
	print_color(list->path, *op, 0);
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
	ft_printf("\n");
}

void	print_other(t_lst *list, t_options *op, int *a)
{
	DIR *dp;

	if ((dp = opendir(list->path)) != NULL)
	{
		((*op).rac)--;
		*a = 0;
	}
	else
	{
		print_color(list->path, *op, 0);
		if (op->ff == 1 || op->p == 1)
			print_ff(list->path, *op);
		ft_putchar('\n');
	}
}

int		print_file_l(t_lst *list, t_options *op)
{
	struct stat		buf;
	t_width			wid;
	int				a;

	a = 0;
	if (op->l)
		wid = fill_wid(list);
	while (list)
	{
		lstat(list->path, &buf);
		if (S_ISREG(buf.st_mode) == 1 || S_ISLNK(buf.st_mode))
		{
			((*op).rac)++;
			a++;
			if ((*op).l == 1)
				print_lnk(buf, op, wid, list);
			else
				print_other(list, op, &a);
		}
		list = list->next;
	}
	return (a);
}
