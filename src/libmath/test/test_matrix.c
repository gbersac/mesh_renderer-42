/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 16:23:46 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/22 17:06:29 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

#include "libmath.h"

typedef int (*t_test_fc)();

void	launch_test(const char *str, t_test_fc fc)
{
	printf("\t Test for %s\n", str);
	fc();
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
	assert(mat_get(m, 3, 2, NULL) == 8);
	assert(mat_get(m, 5, 1, NULL) == 5);
	assert(mat_get(m, 5, 3, NULL) == 15);
	mat_get(m, 2, 4, &error);
	assert(error == OUT_OF_BOUND);
	mat_get(m, 6, 2, &error);
	assert(error == OUT_OF_BOUND);
	mat_get(NULL, 4, 2, &error);
	assert(error == NO_MATRIX);
	return (1);
}

int		main(void)
{
	launch_test("mat_get", test_get);
	return (EXIT_SUCCESS);
}
