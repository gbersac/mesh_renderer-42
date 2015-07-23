/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:18:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 19:30:28 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "matrix.h"


/*
** Vector are matrix with width of 1.
*/
typedef t_mat	t_vector;

t_mat_type		vec_get(t_vector const * const vec,
						t_uint idx,
						t_matrix_err *err);

/*
** Create a new vector.
*/
t_vector	*vec_new(t_uint size);
t_vector	*vec_new3(t_mat_type v1, t_mat_type v2, t_mat_type v3);

float		vec_length(t_vector *vec);

/*
** Normalize the vector (make its length= 1)
*/
void		vec_normalize(t_vector *);

/*
** This is the view matrix.
*/
t_mat		*math_look_at(t_vector const *eye,
						t_vector const *center,
						t_vector const *up);

/*
** Cross product of two 3d vector.
*/
t_vector	*vec_cross(t_vector *v1, t_vector *v2);

#endif
