/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:10:26 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/12/10 18:25:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		gnlcontenu(int fd, char **stock)
{
	char	*buf;
	char	*temp;
	int		readval;

	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	readval = 1;
	while ((ft_strchr(*stock, '\n') == NULL) && readval > 0)
	{
		temp = *stock;
		readval = read(fd, buf, BUFF_SIZE);
		if (readval > 0)
		{
			buf[readval] = '\0';
			if ((*stock = ft_strjoin(temp, buf)) == NULL)
			{
				*stock = ft_strcat(temp, buf);
				free(buf);
				return (-1);
			}
			free(temp);
		}
	}
	free(buf);
	return (readval);
}

static void		ligne(char **stock, char **line)
{
	char *temp;
	char *bckn_ou_eof;

	temp = *stock;
	bckn_ou_eof = ft_strchr(temp, '\n');
	if (bckn_ou_eof != NULL)
	{
		*line = ft_strsub(temp, 0, bckn_ou_eof - temp);
		*stock = ft_strdup(bckn_ou_eof + 1);
		free(temp);
	}
	else
	{
		*line = ft_strdup(temp);
		free(*stock);
		*stock = NULL;
	}
}

int				get_next_line(int const fd, char **line)
{
	static char		*stock[256];
	int				readval;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000 || fd > 4864)
		return (-1);
	readval = 0;
	if (stock[fd] == NULL)
		if ((stock[fd] = ft_strnew(BUFF_SIZE * 2)) == NULL)
			return (-1);
	if (ft_strchr(stock[fd], '\n') == NULL)
		readval = gnlcontenu(fd, &stock[fd]);
	if (readval == 0 && *stock[fd] == '\0')
	{
		*line = NULL;
		free(stock[fd]);
		stock[fd] = NULL;
	}
	else if ((readval > 0 || *stock[fd] != '\0') && (readval > -1))
	{
		ligne(&stock[fd], line);
		readval = 1;
	}
	return (readval);
}
