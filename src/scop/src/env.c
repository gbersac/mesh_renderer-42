/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:47:18 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/30 15:40:16 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_env		**get_initializable_env()
{
	static t_env	*env = NULL;

	return (&env);
}

void error_callback(int error, const char* description)
{
	printf("GLFW error %d : %s\n", error, description);
}

GLFWwindow	*init()
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n" );
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(WIN_HEIGHT, WIN_WIDTH, "Scop", NULL, NULL);
	if(window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = 1; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return (NULL);
	}
	glGetError();

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	return (window);
}

void		init_env(t_env *env)
{
	*get_initializable_env() = env;
	env->last_time = glfwGetTime();
	env->window = init();
	env->position = vec_new3(0, 0, 5);
	env->mvp = mat_new(4, 4);
}

t_env	*get_env()
{
	return (*get_initializable_env());
}
