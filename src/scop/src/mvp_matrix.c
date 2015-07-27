/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:29:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/27 18:11:23 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "scop.h"

int		test_mvp()
{
	t_mat					*expected;
	t_mat					*mvp;
	static const t_mat_type	defval[] = {
		0.806666,	-0.737824,	-0.687368,	-0.685994,
		0.000000,	1.537134,	-0.515526,	-0.514496,
		-1.075554,	-0.553368,	-0.515526,	-0.514496,
		0.000000,	0.000000,	5.642426,	5.830953
	};

	mvp = mvp_matrix();
	expected = mat_new(4, 4);
	mat_init(expected, defval);
	printf("\n\n");
	mat_print_label(mvp, "result");
	mat_print_label(expected, "expected");
	assert(mat_are_equal(mvp, expected, 0));
	mat_free(&mvp);
	mat_free(&expected);
	return (1);
}

t_mat	*mvp_matrix()
{
	t_mat	*buffer;
	t_mat	*to_return;
	t_mat	*projection;
	t_mat	*model;
	t_mat	*view;

	projection = mat_perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	model = mat_identity(4);
	view = mat_lookat(
		vec_new3(4, 3, 3), // Camera is at (4,3,3), in World Space
		vec_new3(0, 0, 0), // and looks at the origin
		vec_new3(0, 1, 0),  // Head is up (set to 0,-1,0 to look upside-down)
		NULL
	);
	buffer = mat_multi(view, projection, NULL);
	to_return = buffer;
	// multiplication par model ?
	return (to_return);
}
