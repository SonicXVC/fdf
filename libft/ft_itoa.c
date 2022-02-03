/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:33:23 by ameteori          #+#    #+#             */
/*   Updated: 2021/10/20 16:23:23 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_of_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		i;

	i = ft_len_of_int(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(tmp, "-2147483648", 12);
	if (n == 0)
		tmp[0] = '0';
	if (n < 0)
	{
		tmp[0] = '-';
		n = -n;
	}
	tmp[i] = 0;
	while (n > 0)
	{
		*(tmp + (i - 1)) = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (tmp);
}
