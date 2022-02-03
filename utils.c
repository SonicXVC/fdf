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

void	color(int z, int z1, fdf *data)
{
	if (z != 0 || z1 != 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}