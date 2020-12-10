/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mess_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:11:54 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_last_slash(char *str)
{
	int len;

	len = ft_strlen(str);
	while (str[len] != '/' && len >= 0)
		len--;
	return (len + 1);
}

void			bad_dir_err(char *str)
{
	if (str[0] == '\0')
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd("fts_open", 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void			bad_option_err(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-FRagloprt1] [file ...]\n", 2);
	exit(1);
}

void			no_right(char *str, t_options *op)
{
	(*op).err++;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str + ft_last_slash(str), 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
