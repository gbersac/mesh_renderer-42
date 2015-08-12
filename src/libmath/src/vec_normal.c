/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 16:32:09 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:37:44 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat	*vec_normal(t_pt3f *pt1, t_pt3f *pt2, t_pt3f *pt3)
{
	t_mat		*to_return;
	t_vector	*vec1;
	t_vector	*vec2;

	vec1 = vec_new3(pt2->x - pt1->x, pt2->y - pt1->y, pt2->z - pt1->z);
	vec2 = vec_new3(pt3->x - pt1->x, pt3->y - pt1->y, pt3->z - pt1->z);
	to_return = vec_cross(vec1, vec2, NULL);
	mat_free(&vec1);
	mat_free(&vec2);
	return (to_return);
}
