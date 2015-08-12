/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 14:43:42 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:25:39 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "points.h"
# include "matrix.h"

/*
** A quaternion is a matrix of width 1 (vector) and height 4.
** It is a float array with attributes stored this way : x y z w (w is last !!!)
** Cast quat->array to t_pt4f to make things easier : (t_pt4f)quat->array
*/
typedef t_vector	t_quaternion;

/*
** Rotate the quaternion about the axis v (unit vector).
** v :	This vector should be normalized.
*/
t_quaternion	*quat_rotate_axis(t_vector *v, float angle);

/*
** Convert a quaternion to a rotation matrix
*/
t_mat			*quat_to_matrix(t_quaternion *q);

/*
** Quaternion multiplication.
** It is not commutative => quat_multi(q1, q2) != quat_multi(q2, q1)
*/
t_quaternion	*quat_multi(t_quaternion *q1, t_quaternion *q2);

#endif
