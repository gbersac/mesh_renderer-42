#ifndef SCOP_H
#define SCOP_H

# include <stdio.h>

# define GLEW_NO_GLU
# include <glew.h>
# include <glfw3.h>
# include <OpenGL/gl.h>

# include "shader.h"
# include "libmath.h"

t_mat		*mvp_matrix();
int			test_mvp();

#endif
