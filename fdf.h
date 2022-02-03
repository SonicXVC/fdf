/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:50:34 by ameteori          #+#    #+#             */
/*   Updated: 2022/02/03 19:00:35 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct
{
	int		width;
	int 	height;
	int 	**z_matrix;
	int 	zoom;
	int 	color;
	int		shift_x;
	int 	shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

float	modulo(float a);
float	maximum(float a, float b);
void	color(int z, int z1, fdf *data);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	fill_matrix(int *z_line, char *line);
void	read_file(char *file_name, fdf *data);
void	formula(t_point tmp, t_point tmp1, fdf *data);
void	isom(float *x, float *y, int z);
int		deal_mouse(int key, fdf *data);
int		deal_key(int key, fdf *data);
void	draw(fdf *data);

#endif
