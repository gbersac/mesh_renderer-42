/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:37:20 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/27 13:33:50 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	one_multi(t_mat const * const m1, t_mat const * const m2,
						t_mat_type x, t_mat_type y)
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
	x = m1->height;
	y = m2->height;
	return (to_return);
}

t_mat		*mat_multi(t_mat const * const m1, t_mat const * const m2,
					t_matrix_err *error)
{
	t_mat	*to_return;
	t_uint		i;
	t_uint		j;

	if (m1 == NULL || m2 == NULL)
		return (mat_ret(error, NO_MATRIX));
	if (m1->width != m2->height)
		return (mat_ret(error, INCOMPATIBLE_SIZE));
	to_return = mat_new(m2->width, m1->height);
	i = 0;
	while (i < to_return->width)
	{
		j = 0;
		while (j < to_return->height)
		{
			mat_set(to_return, j, i, one_multi(m1, m2, i, j));
			++j;
		}
		++i;
	}
	mat_ret(error, NO_ERROR);
	return (to_return);
}
