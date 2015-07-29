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
	env->last_time = glfwGetTime();
	env->window = init();
	env->position = vec_new3(0, 0, 5);
	env->mvp = mat_new(4, 4);
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

	GLuint MatrixID = glGetUniformLocation(shader_texture->program_id, "MVP");
	do{
		// printf("Begin: ");check_gl_error();
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use our shader
		glUseProgram(shader_texture->program_id);

		mvp_matrix(&env);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, env.mvp->array);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(texture_id, 0);

		gl_display_object(mesh_cube);

		glfwSwapBuffers(env.window);
		glfwPollEvents();
		// printf("End: ");check_gl_error();
	}
	while( glfwGetKey(env.window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(env.window) == 0 );

	// Cleanup VBO
	// TODO clean mesh
	// glDeleteBuffers(1, &vertex_buff);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader_color->program_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return (EXIT_SUCCESS);
}
