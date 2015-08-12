/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 15:21:52 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:35:09 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libmath.h"

t_quaternion	*quat_multi(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	*to_return;
	t_pt4f			*p1;
	t_pt4f			*p2;

	to_return = vec_new(4);
	p1 = (t_pt4f*)q1->array;
	p2 = (t_pt4f*)q2->array;
	mat_set(to_return, 0, 0,
		p1->w * p2->x + p1->x * p2->w + p1->y * p2->z - p1->z * p2->y);
	mat_set(to_return, 1, 0,
		p1->w * p2->y + p1->y * p2->w + p1->z * p2->x - p1->x * p2->z);
	mat_set(to_return, 2, 0,
		p1->w * p2->z + p1->z * p2->w + p1->x * p2->y - p1->y * p2->x);
	mat_set(to_return, 3, 0,
		p1->w * p2->w - p1->x * p2->x - p1->y * p2->y - p1->z * p2->z);
	return (to_return);
}
