/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:14:50 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:36:44 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	m(t_vector const *const v1, t_vector const *const v2,
				int i1, int i2)
{
	return (v1->array[i1] * v2->array[i2]);
}

t_vector	*vec_cross(t_vector const *const v1, t_vector const *const v2,
						t_matrix_err *err)
{
	t_vector	*to_return;

	if (v1 == NULL || v2 == NULL)
		return (mat_ret(err, NO_MATRIX));
	if (v1->height != 3 || v2->height != 3)
		return (mat_ret(err, INCOMPATIBLE_SIZE));
	to_return = vec_new(3);
	to_return->array[0] = v1->array[1] * v2->array[2] -
			v1->array[2] * v2->array[1];
	to_return->array[1] = v1->array[2] * v2->array[0] -
			v1->array[0] * v2->array[2];
	to_return->array[2] = v1->array[0] * v2->array[1] -
			v1->array[1] * v2->array[0];
	mat_ret(err, NO_ERROR);
	return (to_return);
}
