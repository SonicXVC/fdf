/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:42:24 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/19 19:32:02 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_mall(char const *s, unsigned int start, size_t len)
{
	char			*tmp;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		tmp = (char *)malloc (sizeof(char) * (ft_strlen(s) - start + 1));
	else if (ft_strlen(s) - 1 < start)
		tmp = (char *)malloc (1);
	else
		tmp = (char *)malloc (sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	else
		return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	size_t			i;
	size_t			j;

	tmp = get_mall(s, start, len);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((unsigned int)i >= start && j < len)
		{
			tmp[j] = s[i];
			j++;
		}
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
