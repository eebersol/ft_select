/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:12:03 by eebersol          #+#    #+#             */
/*   Updated: 2016/02/28 21:18:02 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_concat_buff(char **t_buff, char **line)
{
	char *new_line;

	new_line = ft_strchr(*t_buff, '\n');
	*line = ft_strsub(*t_buff, 0, new_line - *t_buff);
	ft_strcpy(*t_buff, new_line + 1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*t_buff[256];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (line == NULL || fd < 0 || fd > 255)
		return (-1);
	if (t_buff[fd] && t_buff[fd][0] && (ft_strchr(t_buff[fd], '\n') != NULL))
		return (ft_concat_buff(&(t_buff[fd]), line));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((t_buff[fd] = ft_freejoin(t_buff[fd], buff)) == NULL)
			return (-1);
		if (ft_strchr(t_buff[fd], '\n') != NULL)
			return (ft_concat_buff(&(t_buff[fd]), line));
	}
	if (ret == -1)
		return (-1);
	if (t_buff[fd] && t_buff[fd][0])
	{
		*line = ft_strdup(t_buff[fd]);
		ft_strdel(&(t_buff[fd]));
		return (1);
	}
	return (0);
}
