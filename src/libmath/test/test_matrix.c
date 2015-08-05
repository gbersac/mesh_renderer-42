/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 16:23:46 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 14:09:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

#include "libmath.h"

typedef int (*t_test_fn)();

void	launch_test(const char *str, t_test_fn fn)
{
	printf("\t Test for %s\n", str);
	fn();
	printf("Test ok\n");
}

int		test_get(void)
{
	t_mat					*m;
	t_matrix_err			error;
	static const t_mat_type	defval[] = {
		1,  2,  3,  4,  5,
		6,  7,  8,  9,  10,
		11, 12, 13, 14, 15
	};

	m = mat_new(5, 3);
	mat_init(m, defval);
	assert(mat_get(m, 1, 2, NULL) == 8);
	assert(mat_get(m, 0, 4, NULL) == 5);
	assert(mat_get(m, 2, 4, NULL) == 15);
	mat_get(m, 3, 1, &error);
	assert(error == OUT_OF_BOUND);
	mat_get(m, 1, 5, &error);
	assert(error == OUT_OF_BOUND);
	mat_get(NULL, 2, 4, &error);
	assert(error == NO_MATRIX);
	mat_free(&m);
	return (1);
}

int		test_set(void)
{
	t_mat					*m;
	t_matrix_err			error;
	static const t_mat_type	defval[] = {
		1,  2,  3,  4,  5,
		6,  7,  8,  9,  10,
		11, 12, 13, 14, 15
	};

	m = mat_new(5, 3);
	mat_init(m, defval);
	mat_set(m, 1, 2, 100);
	assert(mat_get(m, 1, 2, NULL) == 100);
	error = mat_set(m, 3, 1, 100);
	assert(error == OUT_OF_BOUND);
	error = mat_set(m, 1, 5, 100);
	assert(error == OUT_OF_BOUND);
	error = mat_set(NULL, 1, 3, 100);
	assert(error == NO_MATRIX);
	mat_free(&m);
	return (1);
}

int		test_perspective()
{
	t_mat					*m;
	t_mat					*persp;
	static const t_mat_type	defval[] = {
		1.187173, 0.000000,  0.000000,  0.000000,
		0.000000, 2.110530,  0.000000,  0.000000,
		0.000000, 0.000000, -1.020202, -1.000000,
		0.000000, 0.000000, -2.020202,  0.000000
	};

	m = mat_new(4, 4);
	mat_init(m, defval);
	persp = mat_perspective(70, (t_mat_type)16/9, 1, 100);
	// mat_print_label(persp, "result");
	// mat_print_label(m, "expected");
	assert(mat_are_equal(m, persp, 0));

	mat_free(&persp);
	mat_free(&m);
	return (1);
}

int		test_multi()
{
	t_mat					*m1;
	t_matrix_err			error;
	static const t_mat_type	defval[] = {
		1,  2,  3,
		4,  5,  6
	};
	t_mat					*m2;
	static const t_mat_type	defval2[] = {
		10,  11,
		12,  13,
		14,  15
	};
	t_mat					*result;
	static const t_mat_type	defval_exp[] = {
		76,  82,
		184, 199
	};
	t_mat					*expected;

	m1 = mat_new(3, 2);
	mat_init(m1, defval);
	m2 = mat_new(2, 3);
	mat_init(m2, defval2);
	expected = mat_new(2, 2);
	mat_init(expected, defval_exp);
	result = mat_multi(m1, m2, NULL);
	assert(mat_are_equal(expected, result, 0));
	mat_free(&m1);
	mat_free(&m2);
	mat_free(&expected);
	mat_free(&result);
	return (1);
}

int		test_normalize()
{
	t_vector	*vec;

	vec = vec_new3(1, 2, 3);
	vec_normalize(vec);
	assert(fabs(vec_length(vec) - 1) < TOLERANCE);
	mat_free(&vec);
	vec = vec_new3(0, 0, 0);
	vec_normalize(vec);
	assert(vec_length(vec) == 0);
	mat_free(&vec);
	vec = vec_new3(0, 1, -1);
	vec_normalize(vec);
	assert(fabs(vec_length(vec) - 1) < TOLERANCE);
	mat_free(&vec);
	return (1);
}

int		test_cross()
{
	t_vector	*vec1;
	t_vector	*vec2;
	t_vector	*res;
	t_vector	*expected;

	vec1 = vec_new3(1, 2, 3);
	vec2 = vec_new3(4, 5, 6);
	res = vec_cross(vec1, vec2, NULL);
	expected = vec_new3(-3, 6, -3);
	assert(mat_are_equal(res, expected, 0));
	mat_free(&vec1);mat_free(&vec2);mat_free(&res);mat_free(&expected);

	vec1 = vec_new3(-0.685994, -0.514496, -0.514496);
	vec2 = vec_new3(0, 1, 0);
	res = vec_cross(vec1, vec2, NULL);
	// mat_print_label(res, "res");
	expected = vec_new3(0.514496, 0.000000, -0.685994);
	assert(mat_are_equal(res, expected, 0.00001));
	mat_free(&vec1);mat_free(&vec2);mat_free(&res);mat_free(&expected);

	return (1);
}

int		test_subst()
{
	t_mat					*m1;
	t_matrix_err			error;
	static const t_mat_type	defval[] = {
		10, 11, 12,
		13, 14, 15
	};
	t_mat					*m2;
	static const t_mat_type	defval2[] = {
		1,  2,  3,
		4,  5,  6
	};
	t_mat					*result;
	static const t_mat_type	defval_exp[] = {
		9, 9, 9,
		9, 9, 9
	};
	t_mat					*expected;

	m1 = mat_new(3, 2);
	mat_init(m1, defval);
	m2 = mat_new(3, 2);
	mat_init(m2, defval2);
	expected = mat_new(3, 2);
	mat_init(expected, defval_exp);
	result = mat_subst(m1, m2, NULL);
	assert(mat_are_equal(expected, result, 0));
	mat_free(&m1);
	mat_free(&m2);
	mat_free(&expected);
	mat_free(&result);
	return (1);
}

int		test_lookat()
{
	t_mat					*m;
	t_mat					*view;
	static const t_mat_type	defval[] = {
			0.600000, -0.411597, 0.685994, 0.000000,
			0.000000, 0.857493, 0.514496, 0.000000,
			-0.800000, -0.308697, 0.514496, 0.000000,
			0.000000, 0.000000, -5.830953, 1.000000
	};

	m = mat_new(4, 4);
	mat_init(m, defval);
	view = mat_lookat(
	    vec_new3(4, 3, 3), // Camera is at (4,3,3), in World Space
	    vec_new3(0, 0, 0), // and looks at the origin
	    vec_new3(0, 1, 0),  // Head is up (set to 0,-1,0 to look upside-down)
	    NULL
	);
	assert(mat_are_equal(m, view, 0));
	mat_free(&view);
	mat_free(&m);
	return (1);
}

int		test_add()
{
	t_mat					*m1;
	t_matrix_err			error;
	static const t_mat_type	defval[] = {
		10, 11, 12,
		13, 14, -15
	};
	t_mat					*m2;
	static const t_mat_type	defval2[] = {
		1,  2,  3,
		4,  5,  6
	};
	t_mat					*result;
	static const t_mat_type	defval_exp[] = {
		11,	13,	15,
		17,	19,	-9
	};
	t_mat					*expected;

	m1 = mat_new(3, 2);
	mat_init(m1, defval);
	m2 = mat_new(3, 2);
	mat_init(m2, defval2);
	expected = mat_new(3, 2);
	mat_init(expected, defval_exp);
	result = mat_add(m1, m2, NULL);
	assert(mat_are_equal(expected, result, 0));
	mat_free(&m1);
	mat_free(&m2);
	mat_free(&expected);
	mat_free(&result);
	return (1);
}

int		test_length()
{
	t_vector *v = vec_new3(4, 4, 2);
	assert(vec_length(v) == 6);
	mat_free(&v);
	return (1);
}

int		main(void)
{
	printf("\nTEST MATRIX !!!\n\n");
	launch_test("mat_get", test_get);
	launch_test("mat_set", test_set);
	launch_test("mat_perspective", test_perspective);
	launch_test("mat_multi", test_multi);
	launch_test("mat_normalize", test_normalize);
	launch_test("mat_cross", test_cross);
	launch_test("mat_subst", test_subst);
	launch_test("mat_lookat", test_lookat);
	launch_test("mat_length", test_length);
	launch_test("mat_add", test_add);
	return (EXIT_SUCCESS);
}
