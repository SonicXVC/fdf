/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:05:39 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/10 17:34:58 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	srcsize;

	destsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	j = destsize;
	i = 0;
	if (destsize < size - 1 && size > 0)
	{
		while (src[i] && destsize + i < size - 1)
		{
			dst[j] = src [i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (destsize >= size)
		destsize = size;
	return (destsize + srcsize);
}
