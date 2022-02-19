/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:53:21 by ameteori          #+#    #+#             */
/*   Updated: 2022/02/05 19:03:08 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw(t_fdf *data)
{
	int	i;
	int	j;

	data->color = 0;
	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			my_mlx_pixel_put(data, i, j, data->color);
			j++;
		}
		i++;
	}
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 53)
		exit(0);
	if (key == 13)
		data->zoom += 2;
	if (key == 1)
		data->zoom -= 2;
	redraw(data);
	color(0, 0, data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	close_fdf(t_fdf *data)
{
	(void) data;
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	(void)ac;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
					&data->line_length, &data->endian);
	data->zoom = 15;
	data->shift_x = 500;
	data->shift_y = 500;
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_fdf, data);
	mlx_loop(data->mlx_ptr);
}
