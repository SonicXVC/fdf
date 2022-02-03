/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:12 by ameteori          #+#    #+#             */
/*   Updated: 2022/01/18 17:43:56 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_of_strs(const char *s, char c)
{
	unsigned int		i;
	unsigned int		nb;

	i = 0;
	nb = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb++;
	return (nb);
}

void	ft_str(char **next_str, unsigned int *next_strlen, char c)
{
	unsigned int	i;

	*next_str += *next_strlen;
	*next_strlen = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_strlen)++;
		i++;
	}
}

char	**ft_fun(char const **s, char *c, unsigned int *nb)
{
	char				**tmp;

	if (!*s)
		return (0);
	*nb = ft_nb_of_strs(*s, *c);
	tmp = (char **)malloc(sizeof(char *) * (*nb + 1));
	if (!tmp)
		return (0);
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i;
	unsigned int		nb;
	unsigned int		next_strlen;
	char				**tmp;
	char				*next_str;

	tmp = ft_fun(&s, &c, &nb);
	if (tmp == 0)
		return (0);
	next_str = (char *)s;
	next_strlen = 0;
	i = 0;
	while (i < nb)
	{
		ft_str(&next_str, &next_strlen, c);
		tmp[i] = (char *)malloc(sizeof(char) * (next_strlen + 1));
		if (!tmp[i])
			return (0);
		ft_strlcpy(tmp[i], next_str, next_strlen + 1);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
