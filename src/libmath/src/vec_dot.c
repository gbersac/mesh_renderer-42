/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 14:01:05 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:37:04 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type		vec_dot(t_vector const *const v1, t_vector const *const v2,
						t_matrix_err *err)
{
	t_mat_type	to_return;
	t_uint		i;

	if (v1 == NULL || v2 == NULL)
	{
		mat_ret(err, NO_MATRIX);
		return (0);
	}
	if (v1->height != v2->height)
	{
		mat_ret(err, INCOMPATIBLE_SIZE);
		return (0);
	}
	to_return = 0;
	i = 0;
	while (i < v1->height)
	{
		to_return += v1->array[i] * v2->array[i];
		++i;
	}
	mat_ret(err, NO_ERROR);
	return (to_return);
}
