// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLM/gtx/string_cast.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>

extern "C"{
#include "scop.h"
}

int main( void )
{
	t_env		env;

	init_env(&env);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);


	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
	GLuint Texture = loadDDS("uvmap.DDS");

	// Get a handle for our "myTextureSampler" uniform

	GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	// Read our .obj file
	t_mesh	*mesh_cube = load_mesh("cube.obj");
	ft_bzero(mesh_cube, 0);

	// do{
	// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 	glUseProgram(programID);

	// 	computeMatricesFromInputs();
	// 	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	// 	glm::mat4 ViewMatrix = getViewMatrix();
	// 	glm::mat4 ModelMatrix = glm::mat4(1.0);
	// 	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
	// 	std::cout << "MVP " << glm::to_string(MVP) << std::endl;

	// 	// Send our transformation to the currently bound shader,
	// 	// in the "MVP" uniform
	// 	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	// 	// Send our transformation to the currently bound shader,
	// 	// in the "MVP" uniform
	// 	// glUniformMatrix4fv(MatrixID, 1, GL_FALSE, env.mvp->array);

	// 	// Bind our texture in Texture Unit 0
	// 	glActiveTexture(GL_TEXTURE0);
	// 	glBindTexture(GL_TEXTURE_2D, Texture);
	// 	// Set our "myTextureSampler" sampler to user Texture Unit 0
	// 	glUniform1i(TextureID, 0);

	// 	gl_display_object(mesh_cube);

	// 	// Draw the triangle !
	// 	glDrawArrays(GL_TRIANGLES, 0, mesh_cube->size);

	// 	glDisableVertexAttribArray(0);
	// 	glDisableVertexAttribArray(1);

	// 	// Swap buffers
	// 	glfwSwapBuffers(env.window);
	// 	glfwPollEvents();

	// } // Check if the ESC key was pressed or the window was closed
	// while( glfwGetKey(env.window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	// 	   glfwWindowShouldClose(env.window) == 0 );
	for (int i = 0; i < 1; ++i)
	{
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
		std::cout << "MVP " << glm::to_string(MVP) << std::endl;
	}

	// Cleanup VBO and shader
	// glDeleteBuffers(1, &vertexbuffer);
	// glDeleteBuffers(1, &uvbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &TextureID);
	glDeleteVertexArrays(1, &VertexArrayID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


