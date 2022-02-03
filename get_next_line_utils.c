/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:33:03 by ameteori          #+#    #+#             */
/*   Updated: 2022/01/20 16:22:15 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr1(const char *ostatok, char c)
{
	if (!ostatok)
		return (NULL);
	while (*ostatok != c)
	{
		if (!*ostatok++)
			return (0);
	}
	return ((char *)ostatok);
}

char	*ft_strjoin1(char *ostatok, char *buff)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = -1;
	j = 0;
	if (!ostatok)
	{
		ostatok = (char *)malloc(sizeof(char) * 1);
		ostatok[0] = '\0';
	}
	if (!ostatok || !buff)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(ostatok) + ft_strlen(buff) + 1));
	if (!tmp)
		return (NULL);
	if (ostatok)
		while (ostatok[++i] != '\0')
			tmp[i] = ostatok[i];
	while (buff[j] != '\0')
		tmp[i++] = buff[j++];
	tmp[ft_strlen(ostatok) + ft_strlen(buff)] = '\0';
	free (ostatok);
	return (tmp);
}

char	*ft_dup_line(char *ostatok)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!ostatok[i])
		return (NULL);
	while (ostatok[i] && ostatok[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (ostatok[i] && ostatok[i] != '\n')
	{
		tmp[i] = ostatok[i];
		i++;
	}
	if (ostatok[i] == '\n')
	{
		tmp[i] = ostatok[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*new_ost(char *ostatok)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (ostatok[i] && ostatok[i] != '\n')
		i++;
	if (!ostatok[i])
	{
		free(ostatok);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(ostatok) - i + 2));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (ostatok[i])
		tmp[j++] = ostatok[i++];
	free(ostatok);
	tmp[j] = '\0';
	return (tmp);
}
