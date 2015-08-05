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

int	test_axis()
{
	t_vector *v = vec_new3(0.298142, -0.745356, 0.596285);
	t_quaternion *result = quat_rotate_axis(v, 0.5f);
	t_quaternion *model = vec_new4(0.073762 , -0.184404, 0.147523, 0.968912);
	// mat_print_label(result, "result");
	// print_pt4f((t_pt4f*)result->array);
	// mat_print_label(model, "model");
	// print_pt4f((t_pt4f*)model->array);
	assert(mat_are_equal(result, model, 0));
	mat_free(&v);mat_free(&result);mat_free(&model);
	return (1);
}

int	test_multi1()
{
	t_quaternion	*q1;
	t_quaternion	*q2;
	t_quaternion	*model;
	t_quaternion	*result;

	q1 = vec_new4(1, 2, 3, 4);
	q2 = vec_new4(5, 6, 7, 8);
	result = quat_multi(q1, q2);
	model = vec_new4(24, 48, 48, -6);
	// mat_print_label(result, "result");
	// mat_print_label(model, "model");
	assert(mat_are_equal(result, model, 0));
	mat_free(&q1);mat_free(&q2);mat_free(&result);mat_free(&model);
	return (1);
}

int	test_multi2()
{
	t_quaternion	*q1;
	t_quaternion	*q2;
	t_quaternion	*model;
	t_quaternion	*result;

	q1 = vec_new4(0, 0, 0, 0);
	q2 = vec_new4(5, 6, 7, 8);
	result = quat_multi(q1, q2);
	model = vec_new4(0, 0, 0, 0);
	assert(mat_are_equal(result, model, 0));
	mat_free(&q1);mat_free(&q2);mat_free(&result);mat_free(&model);
	return (1);
}

int	test_matrix()
{
	t_mat			*model;
	t_mat			*result;
	t_quaternion	*q;
	static const t_mat_type	defval[] = {
		-25.000000, -20.000000, 22.000000, 0.000000,
		28.000000, -19.000000, 4.000000, 0.000000,
		-10.000000, 20.000000, -9.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};

	model = mat_new(4, 4);
	mat_init(model, defval);
	q = vec_new4(1, 2, 3, 4);
	result = quat_to_matrix(q);
	assert(mat_are_equal(result, model, 0));
	mat_free(&q);mat_free(&result);mat_free(&model);
	return (1);
}

/*
** If still a bug, watch, I inverted value [0, 2] and [2, 0] compared to
** model tutorial17.cpp
*/
int	test_matrix2()
{
	t_mat			*model;
	t_mat			*result;
	t_quaternion	*q;

	static const t_mat_type	defval[] = {
		0.888574, 0.000000, -0.458733, 0.000000,
		-0.000000, 1.000000, 0.000000, 0.000000,
		0.458733, -0.000000, 0.888574, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};

	model = mat_new(4, 4);
	mat_init(model, defval);
	q = vec_new4(0, -0.236036, 0, 0.971744);
	result = quat_to_matrix(q);
	// mat_print_label(result, "result");
	// mat_print_label(model, "model");
	assert(mat_are_equal(result, model, 0));
	mat_free(&q);mat_free(&result);mat_free(&model);
	return (1);
}

int		main(void)
{
	printf("\nTEST MATRIX !!!\n\n");
	launch_test("quat_from_axis", test_axis);
	launch_test("quat_multi1", test_multi1);
	launch_test("quat_multi2", test_multi2);
	launch_test("quat_matrix", test_matrix);
	launch_test("quat_matrix2", test_matrix2);
	return (EXIT_SUCCESS);
}
