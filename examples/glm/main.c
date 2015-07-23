#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

void	print_mat(glm::mat4 m)
{
	
}

int main()
{
	// Matrices
	glm::mat4 projection;
	glm::mat4 modelview;

	// Initialisation
	projection = glm::perspective(70.0, (double) 16/9, 1.0, 100.0);
	print_mat(projection);
	std::cout << glm::to_string(projection);
}
