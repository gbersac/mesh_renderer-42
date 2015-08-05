/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 14:40:39 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 12:44:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_quaternion	*quat_rotate_axis(t_vector *v, float angle)
{
	float			sinAngle;
	t_quaternion	*to_return;
	t_pt4f			*pt_ret;
	t_pt3f			*pt_direction;

	// print_pt3f((t_pt3f*)v->array);
	vec_normalize(v);
	angle *= 0.5f;
	sinAngle = sin(angle);
	to_return = vec_new(4);
	pt_ret = (t_pt4f*)to_return->array;
	pt_direction = (t_pt3f*)v->array;
	pt_ret->x = (pt_direction->x * sinAngle);
	// printf("pt_direction->x %f * sinAngle %f = pt_ret->x %f\n",
	// 		pt_direction->x, sinAngle, pt_ret->x);
	pt_ret->y = (pt_direction->y * sinAngle);
	pt_ret->z = (pt_direction->z * sinAngle);
	pt_ret->w = cos(angle);
	// printf(" cos angle %f\n", cos(angle));
	return (to_return);
}
