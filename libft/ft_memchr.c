/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:09:45 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/10 16:10:42 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	c2;
	int				i;

	tmp = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (tmp[i] != c2)
			i++;
		else
			return (tmp + i);
	}
	return (0);
}
