/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_scalar_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:42:34 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:33:53 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			mat_scalar_multi(t_mat *const m, t_mat_type multiplicator,
					t_matrix_err *err)
{
	t_uint		x;
	t_uint		y;
	t_mat_type	initial_val;

	if (m == NULL)
	{
		mat_ret(err, NO_MATRIX);
		return ;
	}
	x = 0;
	while (x < m->width)
	{
		y = 0;
		while (y < m->height)
		{
			initial_val = mat_get(m, y, x, NULL);
			mat_set(m, y, x, multiplicator * initial_val);
			++y;
		}
		++x;
	}
	mat_ret(err, NO_ERROR);
}
