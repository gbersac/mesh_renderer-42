/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 13:33:38 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/24 13:35:49 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_matrix_err	mat_neg(t_mat *m)
{
	t_uint	i;
	t_uint	size;

	if (m = NULL)
		return (NO_MATRIX);
	size = m->width * m->height;
	i = 0;
	while (i < size)
	{
		m->array[i] = -m->array[i];
		++i;
	}
	return (NO_ERROR);
}
