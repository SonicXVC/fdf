/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:25:36 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/16 18:24:20 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	size_t	lenght;

	lenght = ft_strlen(src) + 1;
	tmp = (char *)malloc(sizeof(*src) * lenght);
	if (!tmp)
		return (0);
	else
		ft_memcpy(tmp, src, lenght);
	return (tmp);
}
