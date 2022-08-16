/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:23:02 by sabazyan          #+#    #+#             */
/*   Updated: 2022/04/25 20:14:53 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*loop(int fd, char *static_line)
{
	char	buf[BUFFER_SIZE + 1];
	int		for_read;

	while (1)
	{
		for_read = read(fd, buf, BUFFER_SIZE);
		buf[for_read] = '\0';
		if (for_read == -1)
			return (NULL);
		if (!static_line)
			static_line = ft_strdup(buf);
		else
			static_line = ft_strjoin(static_line, buf);
		if (ft_strchr(buf, '\n') || for_read == 0)
			break ;
	}
	return (static_line);
}

char	*get_next_line(int fd)
{
	int			index_n;
	char		*result;
	static char	*static_line[OPEN_MAX];
	char		*temp;
	int			second_part;

	static_line[fd] = loop(fd, static_line[fd]);
	second_part = ft_strlen(ft_strchr(static_line[fd], '\n'));
	index_n = ft_strlen(static_line[fd]) - second_part + 1;
	result = ft_substr(static_line[fd], 0, index_n);
	temp = static_line[fd];
	static_line[fd] = ft_substr(temp, index_n, ft_strlen(temp));
	free(temp);
	return (result);
}
