/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 18:59:31 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/26 22:51:54 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	vec_normalize(t_vector *vec)
{
	float	length;
	t_uint	i;

	length = vec_length(vec);
	i = 0;
	while (i < vec->height)
	{
		vec->array[i] = vec->array[i] / length;
		++i;
	}
}
