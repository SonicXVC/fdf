/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:32:26 by ameteori          #+#    #+#             */
/*   Updated: 2022/02/05 18:23:14 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	shift(t_point *tmp, t_point *tmp1, t_point *step, t_fdf *data)
{
	tmp->x += data->shift_x;
	tmp->y += data->shift_y;
	tmp1->x += data->shift_x;
	tmp1->y += data->shift_y;
	step->x = tmp1->x - tmp->x;
	step->y = tmp1->y - tmp->y;
}

void	isom(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	formula(t_point tmp, t_point tmp1, t_fdf *data)
{
	t_point	step;
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
	shift(&tmp, &tmp1, &step, data);
	max = maximum(modulo(step.x), modulo(step.y));
	step.x /= max;
	step.y /= max;
	while ((int)(tmp.x - tmp1.x) || (int)(tmp.y - tmp1.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, tmp.x, tmp.y, data->color);
		tmp.x += step.x;
		tmp.y += step.y;
	}
}

void	draw(t_fdf *data)
{
	t_point	tmp;
	t_point	tmp1;

	tmp.y = 0;
	while (tmp.y < data->height)
	{
		tmp.x = 0;
		while (tmp.x < data->width)
		{
			if (tmp.x < data->width - 1)
			{
				tmp1.x = tmp.x + 1;
				tmp1.y = tmp.y;
				formula(tmp, tmp1, data);
			}
			if (tmp.y < data->height - 1)
			{
				tmp1.x = tmp.x;
				tmp1.y = tmp.y + 1;
				formula(tmp, tmp1, data);
			}
			tmp.x++;
		}
		tmp.y++;
	}
}
