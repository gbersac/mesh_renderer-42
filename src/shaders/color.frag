#version 330 core

// Ouput data
out vec3 color;
in vec3 fragmentColor;

void main()
{
	// Output color = red
	color = fragmentColor;

}
