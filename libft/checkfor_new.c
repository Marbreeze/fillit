/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfor_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:20:07 by mstratu           #+#    #+#             */
/*   Updated: 2019/04/18 18:20:24 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				checkfor_new(char **temp, char **line, int fd)
{
	int			len;
	char		*valdo;

	len = 0;
	while (temp[fd][len] != '\n' && temp[fd][len] != '\0')
		len++;
	if (temp[fd][len] == '\n')
	{
		*line = ft_strsub(temp[fd], 0, len);
		valdo = ft_strdup(&temp[fd][len + 1]);
		ft_strdel(&temp[fd]);
		temp[fd] = valdo;
	}
	else
	{
		*line = ft_strdup(temp[fd]);
		ft_strdel(&temp[fd]);
	}
	return (1);
}
