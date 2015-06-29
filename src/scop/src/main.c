#define GLEW_NO_GLU // because you re-implemented some glu-like functions with a different interface
#include <stdio.h>

#include <glew.h>
#include <glfw3.h>
#include <OpenGL/gl.h>

#include "shader.h"

// static void	apple_handling(void)
// {
// #ifdef __APPLE__
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
// 	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// #endif
// }

int main()
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf(stderr, "Failed to initialize GLFW\n" );
		return -1;
	}
	// apple_handling();

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "Scop", NULL, NULL);
	if(window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = 1; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	t_shader *shader1 = load_shader("src/shaders/couleur2d.vert",
			"src/shaders/couleur2d.frag");
	if (shader1 == NULL)
	{
		//TODO free stuff
		return (0);
	}
	// GLuint progID = LoadShaders("src/shaders/couleur2d.vert",
	// 		"src/shaders/couleur2d.frag");

	static const GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,
			 0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	do{
		 // Clear the screen
		 glClear( GL_COLOR_BUFFER_BIT );

		 // Use our shader
		 // glUseProgram(progID);
		 glUseProgram(shader1->program_id);

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

	 } // Check if the ESC key was pressed or the window was closed
	 while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(shader1->program_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return (0);
}
