/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 15:40:14 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/22 16:50:23 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef uint32_t	t_uint;
typedef float		t_mat_type;

typedef struct	s_mat
{
	t_mat_type	*array;
	t_uint		width;
	t_uint		height;
}				t_mat;

t_mat			*mat_new(t_uint width, t_uint height);
void			mat_free(t_mat **to_free);
void			mat_print(t_mat *);

typedef enum	e_matrix_err
{
	NO_ERROR,
	NO_MATRIX,
	OUT_OF_BOUND
}				t_matrix_err;

/*
** Assign all the values of src in dest.
** Make sure that src has, at least, as many number as the dest matrix as box.
*/
void			mat_init(t_mat *dest, t_mat_type const *const src);

/*
** Return one box of the matrix.
** The error pointer can be NULL if you don't intend to check it.
** Error is set to 1 if there is an error, 0 otherwise.
*/
t_mat_type		mat_get(t_mat *m, t_uint x, t_uint y, t_matrix_err *error);

#endif
