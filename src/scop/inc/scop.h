#ifndef SCOP_H
#define SCOP_H

# define WIN_HEIGHT		1024
# define WIN_WIDTH		768

# include <stdio.h>

# define GLEW_NO_GLU
# include <glew.h>
# include <glfw3.h>
# include <OpenGL/gl.h>

# include "shader.h"
# include "libmath.h"

t_mat		*mvp_matrix();
int			test_mvp();

/*
** Create an (and only one) opengl buffer.
*/
GLuint	gl_gen_buffer(GLenum target, GLsizeiptr size,
						GLvoid *data, GLenum usage);

#endif
