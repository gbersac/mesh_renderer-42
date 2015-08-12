/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:18:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:26:43 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "matrix.h"

/*
** Vector are matrix with width of 1.
*/
typedef t_mat	t_vector;

/*
** Getter for vector size. Index start at 0.
*/
t_mat_type		vec_get(t_vector const *const vec,
						t_uint idx,
						t_matrix_err *err);

/*
** Getter for vector size. Index start at 0.
*/
void			vec_set(t_vector *vec,
						t_uint idx,
						t_mat_type value,
						t_matrix_err *err);

/*
** Create a new vector.
*/
t_vector		*vec_new(t_uint size);
t_vector		*vec_new3(t_mat_type v1, t_mat_type v2, t_mat_type v3);
t_vector		*vec_new4(t_mat_type v1, t_mat_type v2,
							t_mat_type v3, t_mat_type v4);

float			vec_length(t_vector const *const vec);

/*
** Normalize the vector (make its length= 1)
*/
void			vec_normalize(t_vector *v);

/*
** This is the view matrix.
*/
t_mat			*math_lookat(t_vector const *eye,
						t_vector const *center,
						t_vector const *up);

/*
** Cross product of two 3d vector.
*/
t_vector		*vec_cross(t_vector const *const v1,
						t_vector const *const v2,
						t_matrix_err *err);

t_mat_type		vec_dot(t_vector const *const v1, t_vector const *const v2,
						t_matrix_err *err);

/*
** This is the function to create the view matrix.
** This matrix will be used to move the world
*/
t_mat			*mat_lookat(t_vector const *eye,
							t_vector const *center,
							t_vector const *up,
							t_matrix_err *err);

/*
** Return the vector perpendicular to the plane of all those points.
*/
t_mat			*vec_normal(t_pt3f *pt1, t_pt3f *pt2, t_pt3f *pt3);

#endif
