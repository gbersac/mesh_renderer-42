#ifndef SCOP_H
#define SCOP_H

# define WIN_HEIGHT			1024
# define WIN_WIDTH			768
# define HORIZONTAL_ANGLE 	3.14f
# define VERTICAL_ANGLE 	0.0f
# define INITIAL_FOV 		45.0f
# define SPEED 				3.0f

# include <stdio.h>

# define GLEW_NO_GLU
# include <glew.h>
# include <glfw3.h>
# include <OpenGL/gl.h>

# include "shader.h"
# include "libmath.h"
# include "libft.h"

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

void		mvp_matrix();
int			test_mvp();

void		init_env(t_env *env);
t_env		*get_env();

/*
** Create one opengl buffer.
*/
GLuint		gl_gen_buffer(GLenum target, GLsizeiptr size,
						GLvoid *data, GLenum usage);

/*
** Load a .bmp teture file.
*/
GLuint		load_bmp(const char * const imagepath);

typedef struct	s_mesh
{
	float		*vertices;
	float		*uvs;
	float		*normals;
	t_uint		size;
	GLuint		gl_buff_vertex;
	GLuint		gl_buff_uv;
}				t_mesh;

t_mesh	*load_mesh(char const * const path);


/*
** This function is displaying an object using opengl.
** The corresponding shader must has been launch and it accept vertices on
** location 0 and uv on location 1.
**
** size :	The number of float in the array (nb_vertices * 3).
*/
void		gl_display_object(t_mesh *mesh);

#endif
