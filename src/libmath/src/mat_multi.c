/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:37:20 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:32:59 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	one_multi(t_mat const *const m1, t_mat const *const m2,
						t_uint y, t_uint x)
{
	t_uint			i;
	t_mat_type		to_return;
	t_matrix_err	error;

	i = 0;
	to_return = 0;
	while (i < m1->width)
	{
		to_return += mat_get(m1, y, i, &error) *
				mat_get(m2, i, x, &error);
		++i;
	}
	return (to_return);
}

t_mat		*mat_multi(t_mat const *const m1, t_mat const *const m2,
					t_matrix_err *error)
{
	t_mat	*to_return;
	t_uint	x;
	t_uint	y;

	if (m1 == NULL || m2 == NULL)
		return (mat_ret(error, NO_MATRIX));
	if (m1->width != m2->height)
		return (mat_ret(error, INCOMPATIBLE_SIZE));
	to_return = mat_new(m2->width, m1->height);
	x = 0;
	while (x < to_return->width)
	{
		y = 0;
		while (y < to_return->height)
		{
			mat_set(to_return, y, x, one_multi(m1, m2, y, x));
			++y;
		}
		++x;
	}
	mat_ret(error, NO_ERROR);
	return (to_return);
}
