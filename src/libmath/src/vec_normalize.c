/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 18:59:31 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 14:08:58 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static int	test_vec_zero(t_vector *vec)
{
	t_uint		i;

	i = 0;
	while (i < vec->height)
	{
		if (vec_get(vec, i, NULL) != 0)
			return (0);
		++i;
	}
	return (1);
}

void		vec_normalize(t_vector *vec)
{
	float	length;
	t_uint	i;

	if (vec == NULL)
		return ;
	length = vec_length(vec);
	if (fabs(length - 1) < TOLERANCE || (length == 0 && test_vec_zero(vec)))
		return ;
	i = 0;
	while (i < vec->height)
	{
		vec->array[i] = vec->array[i] / length;
		++i;
	}
}
