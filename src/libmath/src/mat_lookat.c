/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:14:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:32:30 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static void	init_mat(t_mat *to_return, t_vector *s, t_vector *u, t_vector *f)
{
	mat_set(to_return, 0, 0, vec_get(s, 0, NULL));
	mat_set(to_return, 1, 0, vec_get(s, 1, NULL));
	mat_set(to_return, 2, 0, vec_get(s, 2, NULL));
	mat_set(to_return, 0, 1, vec_get(u, 0, NULL));
	mat_set(to_return, 1, 1, vec_get(u, 1, NULL));
	mat_set(to_return, 2, 1, vec_get(u, 2, NULL));
	mat_set(to_return, 0, 2, -vec_get(f, 0, NULL));
	mat_set(to_return, 1, 2, -vec_get(f, 1, NULL));
	mat_set(to_return, 2, 2, -vec_get(f, 2, NULL));
}

t_mat		*mat_lookat(t_vector const *eye,
						t_vector const *center,
						t_vector const *up,
						t_matrix_err *err)
{
	t_mat		*to_return;
	t_vector	*f;
	t_vector	*s;
	t_vector	*u;

	if (eye == NULL || center == NULL || up == NULL)
		return (mat_ret(err, NO_MATRIX));
	if (eye->height != 3 || center->height != 3 || up->height != 3)
		return (mat_ret(err, INCOMPATIBLE_SIZE));
	f = mat_subst(center, eye, err);
	vec_normalize(f);
	u = mat_cpy(up);
	vec_normalize(u);
	s = vec_cross(f, u, NULL);
	vec_normalize(s);
	mat_free(&u);
	u = vec_cross(s, f, NULL);
	to_return = mat_identity(4);
	init_mat(to_return, s, u, f);
	mat_set(to_return, 3, 0, -vec_dot(s, eye, NULL));
	mat_set(to_return, 3, 1, -vec_dot(u, eye, NULL));
	mat_set(to_return, 3, 2, vec_dot(f, eye, NULL));
	mat_ret(err, NO_ERROR);
	return (to_return);
}
