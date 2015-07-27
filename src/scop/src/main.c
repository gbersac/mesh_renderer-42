#include "scop.h"
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
	window = glfwCreateWindow(1024, 768, "Scop", NULL, NULL);
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

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	return (window);
}

int			main()
{
	GLFWwindow* window;

	window = init();
	if (window == NULL)
		return (EXIT_FAILURE);
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	t_shader *shader1 = load_shader("src/shaders/SimpleTransform.vertexshader",
			"src/shaders/SingleColor.fragmentshader");
	if (shader1 == NULL)
	{
		//TODO free stuff
		printf("Error sheder construction\n");
		return (0);
	}

	static const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
	};
	// static const GLushort g_element_buffer_data[] = { 0, 1, 2 };

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	t_mat	*mvp = mvp_matrix();
	mat_print_label(mvp, "mvp");
	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(shader1->program_id, "MVP");

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp->array);
	do{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(shader1->program_id);

		// Send our transformation to the currently bound shader,
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, mvp->array);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader1->program_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return (EXIT_SUCCESS);
}
