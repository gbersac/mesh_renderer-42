/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 18:48:28 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 18:50:21 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vector	*vec_new3(t_mat_type v1, t_mat_type v2, t_mat_type v3)
{
	t_vector	*to_return;

	to_return = vec_new(3);
	to_return->array[0] = v1;
	to_return->array[1] = v2;
	to_return->array[2] = v3;
	return (to_return);
}
