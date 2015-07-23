/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:14:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 19:40:18 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat	*math_look_at(t_vector const *eye,
						t_vector const *center,
						t_vector const *up)
{
	// t_mat	*to_return;
	// t_vector const f;//(normalize(center - eye));
	// t_vector const s;//(normalize(cross(f, up)));
	// t_vector const u;//(cross(s, f));

	// f = normalize(center - eye);
	// s = normalize(cross(f, up));
	// u = cross(s, f);
	// detail::tmat4x4<T, P> to_return(1);
	// to_return = mat_new(4, 4);
	// mat_zero(to_return);
	// mat_set(to_return, 1, 1, s.x);
	// mat_set(to_return, 2, 1, s.y);
	// mat_set(to_return, 3, 1, s.z);
	// mat_set(to_return, 1, 2, u.x);
	// mat_set(to_return, 2, 2, u.y);
	// mat_set(to_return, 3, 2, u.z);
	// mat_set(to_return, 1, 3, -f.x);
	// mat_set(to_return, 2, 3, -f.y);
	// mat_set(to_return, 3, 3, -f.z);
	// mat_set(to_return, 4, 1, -dot(s, eye));
	// mat_set(to_return, 4, 2, -dot(u, eye));
	// mat_set(to_return, 4, 3,  dot(f, eye));
	// return (to_return);
	eye = NULL;
	center = NULL;
	up = NULL;
	return (NULL);
}
