/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:59:28 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/19 19:32:29 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	size_t			lenght;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	lenght = ft_strlen(s);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!tmp)
		return (0);
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
