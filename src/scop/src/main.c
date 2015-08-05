#include "scop.h"

void		check_gl_error()
{
	GLenum			err;

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

int			main()
{
	t_env		env;

	init_env(&env);
	if (env.window == NULL)
		return (EXIT_FAILURE);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	t_shader *shader_color = load_shader("src/shaders/simple_transf_color.vert",
			"src/shaders/color.frag");
	t_shader *shader_texture = load_shader("src/shaders/simple_transf_texture.vert",
			"src/shaders/texture.frag");
	if (shader_color == NULL || shader_texture == NULL)
	{
		//TODO free stuff
		printf("Error shader construction\n");
		return (0);
	}
	t_mesh	*mesh_cube = load_mesh("resources/cube.obj");
	GLuint texture = load_bmp("src/uvtemplate.bmp");
	GLuint texture_id  = glGetUniformLocation(shader_texture->program_id,
			"myTextureSampler");

	GLuint gl_mvp_uni = glGetUniformLocation(shader_texture->program_id, "MVP");
	GLuint gl_model_uni = glGetUniformLocation(shader_texture->program_id, "MODEL");
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_texture->program_id);

		mvp_matrix();
		// t_mat *mvp_mat = mat_multi(model_mat, env.mvp, NULL);
		glUniformMatrix4fv(gl_mvp_uni, 1, GL_FALSE, env.mvp->array);
		// free(mvp_mat);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(texture_id, 0);

		gl_display_object(mesh_cube, gl_model_uni);

		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	while( glfwGetKey(env.window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(env.window) == 0 );


	// TODO clean mesh
	// glDeleteBuffers(1, &vertex_buff);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader_color->program_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	texture = 0;
	texture_id = 0;
	gl_mvp_uni = 0;
	mesh_cube = NULL;
	return (EXIT_SUCCESS);
}
