/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 13:21:12 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:28:05 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	mat_get(t_mat const *const m, t_uint y,
				t_uint x, t_matrix_err *error)
{
	t_mat_type	to_return;

	if (m == NULL)
	{
		mat_ret(error, NO_MATRIX);
		return (0);
	}
	if (x >= m->width || y >= m->height)
	{
		mat_ret(error, OUT_OF_BOUND);
		return (0);
	}
	if (error != NULL)
		*error = NO_ERROR;
	to_return = *(m->array + m->width * y + x);
	return (to_return);
}
