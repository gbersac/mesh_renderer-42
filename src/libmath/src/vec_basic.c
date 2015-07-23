/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:26:16 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 19:30:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	vec_get(t_vector const * const vec, t_uint idx, t_matrix_err *err)
{
	t_mat_type	to_return;

	if (m == NULL)
	{
		if (error != NULL)
			*error = NO_MATRIX;
		return (0);
	}
	if (y > m->height)
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
