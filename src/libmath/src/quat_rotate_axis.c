/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 14:40:39 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:35:46 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_quaternion	*quat_rotate_axis(t_vector *v, float angle)
{
	float			sin_angle;
	t_quaternion	*to_return;
	t_pt4f			*pt_ret;
	t_pt3f			*pt_direction;

	vec_normalize(v);
	angle *= 0.5f;
	sin_angle = sin(angle);
	to_return = vec_new(4);
	pt_ret = (t_pt4f*)to_return->array;
	pt_direction = (t_pt3f*)v->array;
	pt_ret->x = (pt_direction->x * sin_angle);
	pt_ret->y = (pt_direction->y * sin_angle);
	pt_ret->z = (pt_direction->z * sin_angle);
	pt_ret->w = cos(angle);
	return (to_return);
}
