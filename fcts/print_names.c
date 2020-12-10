/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:01:21 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_names_bis(struct stat buf, t_width wid, char *timep,
		t_options op)
{
	ft_putchar(' ');
	if (op.g == 1 && op.o == 1)
		ft_putstr("  ");
	if (wid.maj > 0)
	{
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
			print_spaces(wid.maj + 1 - nbr_val(major(buf.st_rdev)));
			ft_printf("%d,", major(buf.st_rdev));
		}
		else
			print_spaces(wid.maj + 2);
	}
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		print_spaces(wid.byt - nbr_val(minor(buf.st_rdev)));
		ft_printf("%jd ", minor(buf.st_rdev));
	}
	else
	{
		print_spaces(wid.byt - nbr_val(buf.st_size));
		ft_printf("%lld ", buf.st_size);
	}
	ft_printf("%.7s", timep + 4);
}

void	print_names_ter(t_options op, t_width wid, struct stat buf)
{
	struct passwd	*pas;
	struct group	*gid;

	pas = getpwuid(buf.st_uid);
	gid = getgrgid(buf.st_gid);
	if (op.g == 0)
	{
		ft_printf(" %s ", pas->pw_name);
		print_spaces(wid.own - ft_strlen(pas->pw_name));
	}
	if (op.o == 0)
	{
		ft_printf(" %s ", gid->gr_name);
		print_spaces(wid.grp - ft_strlen(gid->gr_name));
	}
}

void	print_names(struct stat buf, t_options op, t_width wid)
{
	char	*timep;
	time_t	i;

	i = 0;
	timep = ctime(&(buf.st_mtime));
	print_spaces(wid.lks - nbr_val(buf.st_nlink));
	print_spaces(wid.acl);
	ft_printf("%hu", buf.st_nlink);
	print_names_ter(op, wid, buf);
	print_names_bis(buf, wid, timep, op);
	if ((timep)[20] == ' ')
		ft_printf(" %.5s ", timep + 24);
	else if (buf.st_mtime > time(&i) || (time(&i) - buf.st_mtime) > 15552000)
		ft_printf(" %.4s ", timep + 20);
	else
		ft_printf("%.5s ", timep + 11);
}
