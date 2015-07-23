/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 18:53:25 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 19:06:35 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float		vec_length(t_vector *vec)
{
	float	to_return;
	t_uint	i;
	float	cumul;

	to_return = 0;
	i = 0;
	while (i < vec->height)
	{
		cumul = vec->array[i] * vec->array[i];
		++i;
	}
	to_return = sqrtf(cumul);
	return (to_return);
}
