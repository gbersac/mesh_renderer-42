#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

out vec2 UV;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 MVP;
uniform mat4 MODEL;

void main()
{
    // Output position of the vertex, in clip space : MVP * position
    gl_Position = MVP * MODEL * vec4(position, 1);

    // output
    FragPos = vec3(MODEL * vec4(position, 1.0f));
    UV = vertexUV;
    Normal = mat3(transpose(inverse(MODEL))) * vertexNormal;
}
