/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 13:21:15 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:34:07 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_matrix_err	mat_set(t_mat *m, t_uint y, t_uint x, t_mat_type val)
{
	if (m == NULL)
		return (NO_MATRIX);
	if (x >= m->width || y >= m->height)
		return (OUT_OF_BOUND);
	m->array[m->width * y + x] = val;
	return (NO_ERROR);
}
