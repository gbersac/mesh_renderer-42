/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 19:09:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 18:19:02 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void           check_gl_error()
{
	GLenum                  err;

	err = glGetError();
	if (err != GL_NO_ERROR)
	{
		printf("Opengl error : %d ", err);
		switch(err) {
		case GL_INVALID_OPERATION:
			printf("INVALID_OPERATION");
			break;
		case GL_INVALID_ENUM:
			printf("INVALID_ENUM");
			break;
		case GL_INVALID_VALUE:
			printf("INVALID_VALUE");
			break;
		case GL_OUT_OF_MEMORY:
			printf("OUT_OF_MEMORY");
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			printf("INVALID_FRAMEBUFFER_OPERATION");
			break;
		}
		printf("\n");
	}
	else
		printf("No Opengl error\n");
}

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
		glUniform1i(res->texture_id, 0);
		gl_display_object(res, res->mesh, env->mode);
		gl_display_object(res, res->light_mesh, MODE_COLOR);
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
