/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 15:00:44 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:47:43 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_quaternion	*rot_quat(void)
{
	static t_quaternion	*to_return = NULL;
	t_quaternion		*axis;

	if (to_return == NULL)
	{
		axis = vec_new3(0.1, 0, 0.1);
		to_return = quat_rotate_axis(axis, ROTATION_ANGLE);
		vec_normalize(to_return);
		free(axis);
	}
	return (to_return);
}

void				rotate_mesh(t_mesh *m)
{
	t_quaternion	*rotation;
	t_quaternion	*total_rotation;

	rotation = rot_quat();
	total_rotation = quat_multi(rotation, m->rotation);
	vec_normalize(total_rotation);
	mat_free(&m->rotation);
	m->rotation = total_rotation;
}
