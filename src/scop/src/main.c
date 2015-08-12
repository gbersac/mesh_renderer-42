/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 19:09:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:21:20 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		loop(t_env *env, t_resources *res)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	while (glfwGetKey(env->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(env->window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		rotate_mesh(res->mesh);
		mvp_matrix();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, res->texture);
		gl_display_object(res, res->mesh, env->mode);
		glfwSwapBuffers(env->window);
		glfwPollEvents();
	}
}

int			main(int argc, char **argv)
{
	t_env		env;
	t_resources	*resources;

	init_env(&env);
	if (env.window == NULL)
		return (EXIT_FAILURE);
	resources = load_resources(argc, argv);
	if (resources == NULL)
		return (EXIT_FAILURE);
	loop(&env, resources);
	free_resources(resources);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
