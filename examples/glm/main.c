#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <iostream>

void	print_mat(glm::mat4 m)
{

}

glm::mat4x4 lookAt(glm::vec3  const & eye, glm::vec3  const & center, glm::vec3  const & up)
{
	glm::vec3  f = normalize(center - eye);
	glm::vec3  u = normalize(up);
	glm::vec3  s = normalize(cross(f, u));
	u = cross(s, f);

	// std::cout << glm::to_string(cross(f, u)) << std::endl;
	std::cout << "vec f : " << glm::to_string(f) << std::endl;
	std::cout << "vec s : " << glm::to_string(s) << std::endl;
	std::cout << "vec u : " << glm::to_string(u) << std::endl;

	glm::mat4x4 Result(1);
	//	   l  c
	Result[0][0] = s.x;
	Result[1][0] = s.y;
	Result[2][0] = s.z;

	Result[0][1] = u.x;
	Result[1][1] = u.y;
	Result[2][1] = u.z;

	Result[0][2] =-f.x;
	Result[1][2] =-f.y;
	Result[2][2] =-f.z;

	Result[3][0] =-dot(s, eye);
	Result[3][1] =-dot(u, eye);
	Result[3][2] = dot(f, eye);

	std::cout << "vec dot : " << dot(f, eye) << std::endl;

	return Result;
}

glm::vec3 my_cross(glm::vec3 const & x, glm::vec3 const & y)
{
	return glm::vec3(
		x.y * y.z - y.y * x.z,
		x.z * y.x - y.z * x.x,
		x.x * y.y - y.x * x.y);
}

int main()
{
	// Matrices
	glm::mat4 projection;
	glm::mat4 modelview;

	// Initialisation
	// projection = glm::perspective(70.0, (double) 16/9, 1.0, 100.0);
	// print_mat(projection);
	// std::cout << glm::to_string(projection);


	// vec1 = vec_new3(1, 2, 3);
	// vec2 = vec_new3(4, 5, 6);
	// glm::vec3 v = cross(glm::vec3(1, 2, 3), glm::vec3(4, 5, 6));
	// std::cout << glm::to_string(v);


	// glm::vec3 vec1(-0.685994, -0.514496, -0.514496);
	// glm::vec3 vec2(0, 1, 0);
	// std::cout << glm::to_string(my_cross(vec1, vec2)) << std::endl;
	// std::cout << glm::to_string(my_cross(vec1, vec2)) << std::endl;



	glm::mat4 View       = glm::lookAt(
	    glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
	    glm::vec3(0,0,0), // and looks at the origin
	    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	std::cout << glm::to_string(View);

	std::cout << "\n\n\tMy lookAt" << std::endl;
	glm::mat4 myView       = lookAt(
	    glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
	    glm::vec3(0,0,0), // and looks at the origin
	    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	glm::tmat4x4<float> to_return(1);
	std::cout << glm::to_string(myView);

}
