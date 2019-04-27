/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:54:28 by mstratu           #+#    #+#             */
/*   Updated: 2019/04/18 18:20:43 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*temp[FD_MAX];
	char		*text_temp;
	int			num;

	if (!line || fd < 0 || fd > FD_MAX || (read(fd, buf, 0) < 0)
	|| BUFF_SIZE <= 0)
		return (-1);
	if (!temp[fd])
	{
		temp[fd] = ft_strnew(1);
	}
	while ((num = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num] = '\0';
		text_temp = ft_strjoin(temp[fd], buf);
		ft_strdel(&temp[fd]);
		temp[fd] = text_temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (temp[fd][0] == '\0')
		return (0);
	return (checkfor_new(temp, line, fd));
}
