/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:09:28 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/19 19:09:17 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t length)
{
	size_t	i;

	if (!length)
		return ;
	i = 0;
	while (i < length)
	{
		*(unsigned char *)(b + i) = 0;
		i++;
	}
}
