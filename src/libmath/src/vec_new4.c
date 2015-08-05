/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 19:07:44 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/04 19:18:28 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vector	*vec_new4(t_mat_type v1, t_mat_type v2,
						t_mat_type v3, t_mat_type v4)
{
	t_vector	*to_return;

	to_return = vec_new(4);
	to_return->array[0] = v1;
	to_return->array[1] = v2;
	to_return->array[2] = v3;
	to_return->array[3] = v4;
	return (to_return);
}
