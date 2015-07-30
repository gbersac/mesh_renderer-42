/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:29:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/30 20:22:27 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	test_one_position(int key, float delta_time, t_mat *dir, int add)
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

void	update_position(float delta_time, t_mat *direction,
						t_mat *right, t_mat *up)
{
	test_one_position(GLFW_KEY_KP_ADD, delta_time, direction, 1);
	test_one_position(GLFW_KEY_KP_SUBTRACT, delta_time, direction, 0);
	test_one_position(GLFW_KEY_LEFT, delta_time, right, 1);
	test_one_position(GLFW_KEY_RIGHT, delta_time, right, 0);
	test_one_position(GLFW_KEY_DOWN, delta_time, up, 1);
	test_one_position(GLFW_KEY_UP, delta_time, up, 0);
}

void	mvp_matrix()
{
	t_mat			*projection;
	t_mat			*model;
	t_mat			*view;
	t_env			*env;

	env = get_env();
	double currentTime = glfwGetTime();
	float delta_time = (float)currentTime - env->last_time;


	t_vector *direction = vec_new3(
			cos(VERTICAL_ANGLE) * sin(HORIZONTAL_ANGLE),
			sin(VERTICAL_ANGLE),
			cos(VERTICAL_ANGLE) * cos(HORIZONTAL_ANGLE));

	t_vector *right = vec_new3(sin(HORIZONTAL_ANGLE - 3.14f/2.0f), 0,
			cos(HORIZONTAL_ANGLE - 3.14f/2.0f));
	t_vector *up = vec_cross(right, direction, NULL);

	update_position(delta_time, direction, right, up);

	// TODO replace 4.0f / 3.0f by window coordinates
	projection = mat_perspective(INITIAL_FOV, 4.0f / 3.0f, 0.1f, 100.0f);
	model = mat_identity(4);
	t_vector *center = mat_add(env->position, direction, NULL);
	view = mat_lookat(
			env->position,
			center,
			up,
			NULL);
	env->mvp = mat_multi(view, projection, NULL);
	// multiplication par model ?
	mat_free(&direction); mat_free(&right); mat_free(&up); mat_free(&center);

	env->last_time = currentTime;
}
