/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 17:08:05 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 18:19:24 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_quaternion	*rot_quat()
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

t_mat				*model_matrix(t_mesh *mesh)
{
	t_mat			*to_return;
	t_quaternion	*rotation;
	t_quaternion	*total_rotation;

	rotation = rot_quat();
	total_rotation = quat_multi(rotation, mesh->rotation);
	vec_normalize(total_rotation);
	mat_free(&mesh->rotation);
	mesh->rotation = total_rotation;
	to_return = quat_to_matrix(total_rotation);
	return(to_return);
}
