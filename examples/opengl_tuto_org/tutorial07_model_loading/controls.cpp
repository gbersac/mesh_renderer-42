extern "C"{
#include "scop.h"
}
// Include GLFW
#include <iostream>
#include <glfw3.h>

// Include GLM
#include <GLM/gtx/string_cast.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "controls.hpp"



glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}

// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 5 );
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;

void	test_one_position(glm::vec3 &position, int key, float deltaTime, glm::vec3 direction, int add, char *str)
{
	t_env	*env;

	env = get_env();
	// if (glfwGetKey(env->window, key) == GLFW_PRESS){
	if (1)
	{
		if (add)
			position += direction * deltaTime * speed;
		else
			position -= direction * deltaTime * speed;
	}
	std::cout << "position " << glm::to_string(position) << std::endl;
}

void computeMatricesFromInputs()
{
	t_env	*env;

	env = get_env();
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = 0.1;
	// float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(env->window, &xpos, &ypos);

	// Reset mouse position for next frame
	// glfwSetCursorPos(env->window, 1024/2, 768/2);

	// Compute new orientation
	// horizontalAngle += mouseSpeed * float(1024/2 - xpos );
	// verticalAngle   += mouseSpeed * float( 768/2 - ypos );

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f),
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
	glm::vec3 up = glm::cross( right, direction);

	//move
	// test_one_position(position, GLFW_KEY_UP, deltaTime, direction, 1, "deep");
	// test_one_position(position, GLFW_KEY_DOWN, deltaTime, direction, 0, "close");
	test_one_position(position, GLFW_KEY_RIGHT, deltaTime, right, 1, "RIGHT");
	// test_one_position(position, GLFW_KEY_LEFT, deltaTime, right, 0, "LEFT");

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix       = glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );
	std::cout << "position " << glm::to_string(position) << std::endl;
	std::cout << "center " << glm::to_string(position + direction) << std::endl;
	std::cout << "up " << glm::to_string(up) << std::endl;
	std::cout << "direction " << glm::to_string(direction) << std::endl;
	std::cout << "ViewMatrix " << glm::to_string(ViewMatrix) << std::endl;

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
