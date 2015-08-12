/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:47:18 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:50:35 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_env		**get_initializable_env(void)
{
	static t_env	*env = NULL;

	return (&env);
}

static GLFWwindow	*init_glfw(void)
{
	GLFWwindow	*window;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WIN_HEIGHT, WIN_WIDTH, "Scop", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_handler);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	return (window);
}

static void			init_gl(void)
{
	glewExperimental = 1;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return ;
	}
	glGetError();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	printf("press m to switch mode\n");
}

void				init_env(t_env *env)
{
	*get_initializable_env() = env;
	env->last_time = glfwGetTime();
	env->window = init_glfw();
	env->position = vec_new3(0, 0, 5);
	env->mvp = mat_new(4, 4);
	env->mode = MODE_COLOR;
	init_gl();
}

t_env				*get_env(void)
{
	return (*get_initializable_env());
}
