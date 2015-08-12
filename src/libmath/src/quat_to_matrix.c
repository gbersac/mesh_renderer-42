/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 14:42:45 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:36:10 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static void		init_first_line(t_mat *m, t_pt4f *ptq)
{
	mat_set(m, 0, 0, 1.0f - 2.0f * (ptq->y * ptq->y + ptq->z * ptq->z));
	mat_set(m, 0, 1, 2.0f * (ptq->x * ptq->y - ptq->w * ptq->z));
	mat_set(m, 0, 2, 2.0f * (ptq->x * ptq->z + ptq->w * ptq->y));
}

static void		init_second_line(t_mat *m, t_pt4f *ptq)
{
	mat_set(m, 1, 0, 2.0f * (ptq->x * ptq->y + ptq->w * ptq->z));
	mat_set(m, 1, 1, 1.0f - 2.0f * (ptq->x * ptq->x + ptq->z * ptq->z));
	mat_set(m, 1, 2, 2.0f * (ptq->y * ptq->z - ptq->w * ptq->x));
}

static void		init_third_line(t_mat *m, t_pt4f *ptq)
{
	mat_set(m, 2, 0, 2.0f * (ptq->x * ptq->z - ptq->w * ptq->y));
	mat_set(m, 2, 1, 2.0f * (ptq->y * ptq->z + ptq->w * ptq->x));
	mat_set(m, 2, 2, 1.0f - 2.0f * (ptq->x * ptq->x + ptq->y * ptq->y));
}

t_mat			*quat_to_matrix(t_quaternion *quat)
{
	t_mat	*to_return;
	t_pt4f	*ptq;

	to_return = mat_new(4, 4);
	mat_zero(to_return);
	mat_set(to_return, 3, 3, 1);
	ptq = (t_pt4f*)quat->array;
	init_first_line(to_return, ptq);
	init_second_line(to_return, ptq);
	init_third_line(to_return, ptq);
	return (to_return);
}
