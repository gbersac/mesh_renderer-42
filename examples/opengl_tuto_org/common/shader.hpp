#ifndef SHADER_HPP
#define SHADER_HPP

#define GLEW_NO_GLU // because you re-implemented some glu-like functions with a different interface
#include <stdio.h>

#include <glfw3.h>
#include <OpenGL/gl.h>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif
