/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:26 by ameteori          #+#    #+#             */
/*   Updated: 2022/02/03 19:20:39 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	isom(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z;
}

void	formula(t_point tmp, t_point tmp1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)tmp.y][(int)tmp.x];
	z1 = data->z_matrix[(int)tmp1.y][(int)tmp1.x];
	tmp.x *= data->zoom;
	tmp.y *= data->zoom;
	tmp1.x *= data->zoom;
	tmp1.y *= data->zoom;
	color(z, z1, data);
	isom(&tmp.x, &tmp.y, z);
	isom(&tmp1.x, &tmp1.y, z1);
	tmp.x += data->shift_x;
	tmp.y += data->shift_y;
	tmp1.x += data->shift_x;
	tmp1.y += data->shift_y;
	x_step = tmp1.x - tmp.x;
	y_step = tmp1.y - tmp.y;
	max = maximum(modulo(x_step), modulo(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(tmp.x - tmp1.x) || (int)(tmp.y - tmp1.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, tmp.x, tmp.y, data->color);
		tmp.x += x_step;
		tmp.y += y_step;
	}
}

void	draw(fdf *data)
{
	t_point	tmp;
	t_point	tmp1;
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			tmp.x = x;
			tmp.y = y;
			if (x < data->width - 1)
			{
				tmp1.x = x + 1;
				tmp1.y = y;
				formula(tmp, tmp1, data);
			}
			if (y < data->height - 1)
			{
				tmp1.x = x;
				tmp1.y = y + 1;
				formula(tmp, tmp1, data);
			}
			x++;
		}
		y++;
	}
}
