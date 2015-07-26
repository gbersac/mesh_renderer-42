/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:14:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/26 23:38:05 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat	*mat_lookat(t_vector const *eye,
						t_vector const *center,
						t_vector const *up,
						t_matrix_err *err)
{
	t_mat		*to_return;
	t_vector	*f;//(normalize(center - eye));
	t_vector	*s;//(normalize(cross(f, up)));
	t_vector	*u;//(cross(s, f));

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
	mat_set(to_return, 1, 1, vec_get(s, 1, NULL));
	mat_set(to_return, 1, 2, vec_get(s, 2, NULL));
	mat_set(to_return, 1, 3, vec_get(s, 3, NULL));

	mat_set(to_return, 2, 1, vec_get(u, 1, NULL));
	mat_set(to_return, 2, 2, vec_get(u, 2, NULL));
	mat_set(to_return, 2, 3, vec_get(u, 3, NULL));

	mat_set(to_return, 3, 1, -vec_get(f, 1, NULL));
	mat_set(to_return, 3, 2, -vec_get(f, 2, NULL));
	mat_set(to_return, 3, 3, -vec_get(f, 3, NULL));

	mat_set(to_return, 1, 4, -vec_dot(s, eye, NULL));
	mat_set(to_return, 2, 4, -vec_dot(u, eye, NULL));
	mat_set(to_return, 3, 4, vec_dot(f, eye, NULL));
	mat_ret(err, NO_ERROR);
	return (to_return);
}
