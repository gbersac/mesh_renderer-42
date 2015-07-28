/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:29:23 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/28 18:17:40 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "scop.h"

float		horizontalAngle = 3.14f;
float		verticalAngle = 0.0f;
float		initialFoV = 45.0f;
float		speed = 3.0f; // 3 units / second
float		mouseSpeed = 0.005f;

void	update_position(t_env *env, float delta_time, t_mat *direction,
						t_mat *right)
{
	mat_scalar_multi(direction, delta_time * speed, NULL);
	mat_scalar_multi(right, delta_time * speed, NULL);
	if (glfwGetKey(env->window, GLFW_KEY_UP) == GLFW_PRESS)
		env->position = mat_add(env->position, direction, NULL);
	if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->position = mat_subst(env->position, direction, NULL);
	if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->position = mat_add(env->position, right, NULL);
	if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->position = mat_subst(env->position, right, NULL);
	mat_scalar_multi(right, 1 / delta_time * speed, NULL);
	mat_scalar_multi(direction, 1 / delta_time * speed, NULL);
}

void	mvp_matrix(t_env *env)
{
	t_mat			*projection;
	t_mat			*model;
	t_mat			*view;

	if (env == NULL || env->position == NULL)
		return ;

	//time
	double currentTime = glfwGetTime();
	float delta_time = (float)currentTime - env->last_time;

	t_vector *direction = vec_new3(
			cos(verticalAngle) * sin(horizontalAngle),
			sin(verticalAngle),
			cos(verticalAngle) * cos(horizontalAngle));
	// mat_print_label(direction, "direction");

	t_vector *right = vec_new3(sin(horizontalAngle - 3.14f/2.0f), 0,
			cos(horizontalAngle - 3.14f/2.0f));
	// mat_print_label(right, "right");
	t_vector *up = vec_cross(right, direction, NULL);
	// mat_print_label(up, "up");
	t_vector *center = mat_add(env->position, direction, NULL);

	update_position(env, delta_time, direction, right);
	// mat_print_label(env->position, "updated position");

	projection = mat_perspective(initialFoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// mat_print_label(projection, "projection");
	model = mat_identity(4);
	view = mat_lookat(
			env->position,
			center,
			up,
			NULL);
	// mat_print_label(view, "view");
	env->mvp = mat_multi(view, projection, NULL);
	// multiplication par model ?
	mat_free(&direction); mat_free(&right); mat_free(&up); mat_free(&center);

	env->last_time = currentTime;
}
