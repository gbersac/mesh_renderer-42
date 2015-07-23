/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_perspective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 18:12:14 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 14:46:45 by gbersac          ###   ########.fr       */
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
	mat_set(to_return, 1, 1, 1 / (ratio * tan_half_angle));
	mat_set(to_return, 2, 2, 1 / (tan_half_angle));
	mat_set(to_return, 3, 3, -(far + near) / (far - near));
	mat_set(to_return, 4, 3, -1);
	mat_set(to_return, 3, 4, -(2 * far * near) / (far - near));
	return (to_return);
}
