/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:18:12 by ameteori          #+#    #+#             */
/*   Updated: 2022/02/23 17:16:29 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	modulo(float a)
{
	if (a < 0)
		a = -a;
	return (a);
}

float	maximum(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	color(int z, int z1, t_fdf *data)
{
	if (z != 0 || z1 != 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	int	i;

	if (x < 1920 && y < 1080 && x > 0 && y > 0)
	{
		i = (y * data->line_length + (x * data->bits_per_pixel / 8));
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
}

void	check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_error("ERROR: Bad map path, try: test_maps/....fdf");
	}
	if (ft_strlen(av[1]) < 4)
	{
		ft_error("ERROR: Invalid filename");
	}
	if (av[1][ft_strlen(av[1]) - 1] != 'f'
		|| av[1][ft_strlen(av[1]) - 2] != 'd'
		|| av[1][ft_strlen(av[1]) - 3] != 'f'
		|| av[1][ft_strlen(av[1]) - 4] != '.')
		ft_error("ERROR: Invalid filename");
}
