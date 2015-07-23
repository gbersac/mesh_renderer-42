/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 15:40:29 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 17:17:26 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat		*mat_new(t_uint width, t_uint height)
{
	t_mat	*to_return;

	to_return = (t_mat*)malloc(sizeof(t_mat));
	to_return->array = malloc(width * height * sizeof(t_mat_type));
	to_return->width = width;
	to_return->height = height;
	return (to_return);
}

void		mat_free(t_mat **to_free)
{
	if (to_free == NULL || *to_free == NULL)
		return ;
	free((*to_free)->array);
	free(*to_free);
	*to_free = NULL;
}

void		mat_init(t_mat *dest, t_mat_type const *const src)
{
	memcpy(dest->array, src, dest->width * dest->height * sizeof(t_mat_type));
}

t_mat_type	mat_get(t_mat const * const m, t_uint x,
				t_uint y, t_matrix_err *error)
{
	t_mat_type	to_return;

	if (m == NULL)
	{
		if (error != NULL)
			*error = NO_MATRIX;
		return (0);
	}
	if (x > m->width || y > m->height)
	{
		if (error != NULL)
			*error = OUT_OF_BOUND;
		return (0);
	}
	if (error != NULL)
		*error = NO_ERROR;
	to_return = *(m->array + m->width * (y - 1) + (x - 1));
	return (to_return);
}

t_matrix_err	mat_set(t_mat *m, t_uint x, t_uint y, t_mat_type val)
{
	if (m == NULL)
		return (NO_MATRIX);
	if (x > m->width || y > m->height)
		return (OUT_OF_BOUND);
	m->array[m->width * (y - 1) + (x - 1)] = val;
	return (NO_ERROR);
}

