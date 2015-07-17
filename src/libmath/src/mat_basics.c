#include "libmath.h"

t_mat	*mat_new(uint _width, uint _height)
{
	t_mat	*to_return;

	to_return = malloc(sizeof(t_mat));
	to_return->array = malloc((_width * _height) * sizeof(float));
	to_return->width = _width;
	to_return->height = _height;
	return (to_return);
}

void	mat_free(t_mat **to_free)
{
	free((*to_free)->array);
	free(*to_free);
	*to_free = NULL;
}
