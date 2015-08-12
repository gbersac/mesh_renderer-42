/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:18:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:24:14 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef float		t_mat_type;

typedef struct	s_mat
{
	t_mat_type	*array;
	t_uint		width;
	t_uint		height;
}				t_mat;

t_mat			*mat_new(t_uint width, t_uint height);
void			mat_free(t_mat **m);
void			mat_print(t_mat const *const m);
void			mat_print_label(t_mat const *const m,
									char const *const label);

typedef enum	e_matrix_err
{
	NO_ERROR,
	NO_MATRIX,
	OUT_OF_BOUND,
	INCOMPATIBLE_SIZE,
}				t_matrix_err;

void			mat_print_error(t_matrix_err err);

/*
** Convenience function for matrix. Shouldn't be used out of the lib.
*/
t_mat			*mat_ret(t_matrix_err *error, t_matrix_err val);

/*
** Assign all the values of src in dest.
** Make sure that src has, at least, as many number as the dest matrix as box.
*/
void			mat_init(t_mat *dest, t_mat_type const *const src);

/*
** Init the matrix with zeros;
*/
void			mat_zero(t_mat *dest);

/*
** Return one cell of the matrix. Index begin at 0.
** The error pointer can be NULL if you don't intend to check it.
*/
t_mat_type		mat_get(t_mat const *const m, t_uint x, t_uint y,
						t_matrix_err *error);

/*
** Set the value of the matrix[x, y] to val. Index begin at 0.
** Return the error if there is one.
*/
t_matrix_err	mat_set(t_mat *m, t_uint y, t_uint x, t_mat_type val);

/*
** Return an identity matrix of sixe n x n
*/
t_mat			*mat_identity(t_uint n);
t_mat			*mat_diagonal(t_mat *mat, t_uint n, float val);

/*
** Return a perspective matrix for graphical purpose.
** This is a copy paste of this glm function :
** http://glm.g-truc.net/0.9.4/api/a00151.html
** #ga283629a5ac7fb9037795435daf22560f
** near :	distance between the screen and what is going to be display.
** far :	distance when object will stop being display.
** ratio :	ratio of the screen (16/9...)
** angle :	views angle. The lower the closer to the scene.
** return : a 4x4 projection matrix
*/
t_mat			*mat_perspective(t_mat_type angle, t_mat_type ratio,
						t_mat_type near, t_mat_type far);

/*
** Return 1 if the two matrix are the same, 0 otherwise.
** diff :	number > 0 which is the permission of error. The difference between
** 			two numbers allowed before it is considered different.
*/
int				mat_are_equal(t_mat *m1, t_mat *m2, t_mat_type diff);

/*
** Maticial product
*/
t_mat			*mat_multi(t_mat const *const m1, t_mat const *const m2,
					t_matrix_err *error);

t_mat			*mat_subst(t_mat const *const m1, t_mat const *const m2,
					t_matrix_err *err);

t_mat			*mat_add(t_mat const *const m1, t_mat const *const m2,
					t_matrix_err *err);

/*
** Invert the value of each cell of the matrix.
*/
t_matrix_err	mat_neg(t_mat *m);

t_mat			*mat_cpy(t_mat const *const to_cpy);

void			mat_scalar_multi(t_mat *const m, t_mat_type multiplicator,
					t_matrix_err *err);

t_mat			*mat_translation(t_mat *dest, t_pt3f direction);

#endif
