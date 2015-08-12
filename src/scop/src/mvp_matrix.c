/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:29:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:41:42 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		test_one_position(int key, float delta_time,
									t_mat *dir, int add)
{
	t_env	*env;
	t_mat	*buf;

	env = get_env();
	mat_scalar_multi(dir, delta_time * SPEED, NULL);
	if (glfwGetKey(env->window, key) == GLFW_PRESS)
	{
		buf = env->position;
		if (add)
			env->position = mat_add(env->position, dir, NULL);
		else
			env->position = mat_subst(env->position, dir, NULL);
		mat_free(&buf);
	}
	mat_scalar_multi(dir, 1 / (delta_time * SPEED), NULL);
}

static void		update_position(float delta_time, t_mat *direction,
								t_mat *right, t_mat *up)
{
	test_one_position(GLFW_KEY_KP_ADD, delta_time, direction, 1);
	test_one_position(GLFW_KEY_KP_SUBTRACT, delta_time, direction, 0);
	test_one_position(GLFW_KEY_LEFT, delta_time, right, 1);
	test_one_position(GLFW_KEY_RIGHT, delta_time, right, 0);
	test_one_position(GLFW_KEY_DOWN, delta_time, up, 1);
	test_one_position(GLFW_KEY_UP, delta_time, up, 0);
}

static t_mat	*compute_view(float delta_time, t_vector *direction,
							t_vector *right, t_vector *up)
{
	t_mat		*projection;
	t_vector	*center;
	t_mat		*view;
	t_mat		*mvp;

	update_position(delta_time, direction, right, up);
	projection = mat_perspective(INITIAL_FOV,
			WIN_HEIGHT / WIN_WIDTH, 0.1f, 100.0f);
	center = mat_add(get_env()->position, direction, NULL);
	view = mat_lookat(
			get_env()->position,
			center,
			up,
			NULL);
	mvp = mat_multi(view, projection, NULL);
	mat_free(&projection);
	mat_free(&center);
	mat_free(&view);
	return (mvp);
}

void			mvp_matrix(void)
{
	t_env		*env;
	t_vector	*direction;
	t_vector	*right;
	t_vector	*up;
	float		delta_time;

	env = get_env();
	delta_time = (float)glfwGetTime() - env->last_time;
	env->last_time = glfwGetTime();
	direction = vec_new3(
			cos(VERTICAL_ANGLE) * sin(HORIZONTAL_ANGLE),
			sin(VERTICAL_ANGLE),
			cos(VERTICAL_ANGLE) * cos(HORIZONTAL_ANGLE));
	right = vec_new3(sin(HORIZONTAL_ANGLE - 3.14f / 2.0f), 0,
			cos(HORIZONTAL_ANGLE - 3.14f / 2.0f));
	up = vec_cross(right, direction, NULL);
	env->mvp = compute_view(delta_time, direction, right, up);
	mat_free(&direction);
	mat_free(&right);
	mat_free(&up);
}
