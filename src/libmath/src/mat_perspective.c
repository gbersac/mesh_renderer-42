/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_perspective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 18:12:14 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/27 13:37:29 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_perspective(t_mat_type angle, t_mat_type ratio,
						t_mat_type near, t_mat_type far)
{
	t_mat		*to_return;
	t_mat_type	tan_half_angle;

	to_return = mat_new(4, 4);
	mat_zero(to_return);
	tan_half_angle = tan(angle / 2);
	mat_set(to_return, 0, 0, 1 / (ratio * tan_half_angle));
	mat_set(to_return, 1, 1, 1 / (tan_half_angle));
	mat_set(to_return, 2, 2, -(far + near) / (far - near));
	mat_set(to_return, 2, 3, -1);
	mat_set(to_return, 3, 2, -(2 * far * near) / (far - near));
	return (to_return);
}
