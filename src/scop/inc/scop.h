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

typedef struct	s_env
{
	GLFWwindow	*window;
	t_vector	*position;

	/*
	** The matrix used to move a point from the origin to the world.
	*/
	t_mat		*mvp;

	/*
	** The last time the position has been calculate.
	*/
	double		last_time;
}				t_env;

void		mvp_matrix(t_env *env);
int			test_mvp();

/*
** Create an (and only one) opengl buffer.
*/
GLuint		gl_gen_buffer(GLenum target, GLsizeiptr size,
						GLvoid *data, GLenum usage);

/*
** This function is displaying an object using opengl.
** The corresponding shader must has been launch and it accept vertices on
** location 0 and color on location 1.
**
** size :	The number of float in the array (nb_vertices * 3).
*/
void		gl_display_object(GLuint vertices, GLuint colors, GLuint size);

/*
** Load a .bmp teture file.
*/
GLuint		load_bmp(const char * const imagepath);

#endif
