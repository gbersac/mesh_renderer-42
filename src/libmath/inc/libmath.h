#ifndef LIBMATH_H
# define LIBMATH_H

#include <stdlib.h>

typedef uint32_t uint;

typedef struct	s_mat
{
	float	*array;
	uint	width;
	uint	height;
}				t_mat;

t_mat	*mat_new(uint _width, uint _height);
void	mat_free(t_mat **to_free);

#endif
