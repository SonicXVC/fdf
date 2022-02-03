/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:56:51 by ameteori          #+#    #+#             */
/*   Updated: 2022/01/20 16:22:17 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_ostatok(int fd, char *ostatok)
{
	char	*buff;
	int		chars_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	chars_read = 1;
	while (!ft_strchr1(ostatok, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[chars_read] = '\0';
		ostatok = ft_strjoin1(ostatok, buff);
	}
	free(buff);
	return (ostatok);
}

char	*get_next_line(int fd)
{
	static char		*ostatok;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatok = read_ostatok(fd, ostatok);
	if (!ostatok)
		return (NULL);
	line = ft_dup_line(ostatok);
	ostatok = new_ost(ostatok);
	return (line);
}
