/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:14:50 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 19:41:18 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat_type	m(t_vector *v1, t_vector *v2, int i1, int i2)
{
	return (v1->array[i1] * v2->array[i2]);
}

t_vector	*vec_cross(t_vector *v1, t_vector *v2)
{
	t_vector	*to_return;

	if (v1->height != 3 || v2->height != 3)
		return (NULL);
	to_return = vec_new(3);
	to_return->array[0] = m(v1, v2, 2, 3) - m(v1, v2, 3, 2);
	to_return->array[1] = m(v1, v2, 3, 1) - m(v1, v2, 1, 3);
	to_return->array[2] = m(v1, v2, 1, 2) - m(v1, v2, 2, 1);
	return(to_return);
}
