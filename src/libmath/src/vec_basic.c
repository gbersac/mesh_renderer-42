/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:26:16 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/24 15:52:04 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	vec_get(t_vector const * const vec, t_uint idx, t_matrix_err *err)
{
	t_mat_type	to_return;

	if (vec == NULL)
	{
		mat_ret(err, NO_MATRIX);
		return (0);
	}
	if (idx > vec->height || idx < 1)
	{
		mat_ret(err, OUT_OF_BOUND);
		return (0);
	}
	mat_ret(err, NO_ERROR);
	to_return = *(vec->array + vec->width * (idx - 1));
	return (to_return);
}
