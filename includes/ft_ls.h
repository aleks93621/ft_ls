/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:17:46 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/syslimits.h>
# include "../libft/libft/includes/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <string.h>
# include <stdio.h>
# include <sys/acl.h>
# include <errno.h>

typedef struct	s_options
{
	int		i;
	int		a;
	int		l;
	int		r;
	int		rr;
	int		t;
	int		g;
	int		gg;
	int		o;
	int		p;
	int		err;
	int		aff;
	int		rac;
	int		argc;
	char	**argv;
	int		un;
	int		point;
	int		tiret;
	int		ff;
}				t_options;

typedef struct	s_width
{
	uintmax_t	blk;
	uintmax_t	lks;
	size_t		own;
	size_t		grp;
	uintmax_t	maj;
	uintmax_t	byt;
	int			acl;
	int			err;
}				t_width;

typedef struct	s_lst
{
	struct s_lst	*next;
	char			*path;
}				t_lst;

typedef struct	s_rep
{
	t_lst		*debut;
	t_lst		*fin;
	int			taille;
}				t_rep;

void			init_rep(t_rep *init);
void			lst_init(t_rep *repere, t_lst *lst, t_options *op);
t_lst			*createlist(char *str, t_rep *liste);
void			lst_add_end(t_rep *liste, t_lst *courant, char *str);

void			lst_add_end_bis(t_rep *liste, t_lst *courant, char *str,
		char *path);
t_lst			*createlist_bis(char *str, t_rep *liste, char *path);
t_lst			*fill_doss_bis(t_rep *repere, char *str, t_lst *lst);

int				print_files(t_options *op, t_lst *list, t_rep *rep);
t_lst			*fill_doss(t_rep *repere, t_options op, DIR *dp);

t_options		init_options(int argc, char **argv);
void			fill_options(t_options *opt, int j);

void			sort_lst(t_lst *lst, t_rep *rep, t_options op);
void			sort_t(t_lst *list, t_rep *rep, t_options op);
void			ft_sort(t_lst *list, t_rep *rep, t_options op);

int				print_dir(char *path, t_options op, DIR *dp);

void			bad_option_err(char c);
void			bad_dir_err(char *str);
void			no_right(char *str, t_options *op);
int				check_errors(t_options opt);
void			print_color(char *str, t_options op, int i);

void			free_lst(t_lst *lst, t_rep *rep);

t_lst			*sort_lst2(t_lst *errors, t_rep *rep);

void			print_ff(char *path, t_options op);

void			print_aut(struct stat buf);
void			print_names(struct stat buf, t_options op, t_width wid);
void			print_attrib(char *path, t_width *wid);
void			print_spaces(unsigned long nbr);
uintmax_t		nbr_val(uintmax_t nbr);
void			print_l(t_lst *list, t_options op, char *path);
int				print_file_l(t_lst *list, t_options *op);
t_width			fill_wid(t_lst *list);
#endif
