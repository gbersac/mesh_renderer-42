/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 19:15:28 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:42:33 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define WIN_HEIGHT			1024
# define WIN_WIDTH			768
# define HORIZONTAL_ANGLE 	3.14f
# define VERTICAL_ANGLE 	0.0f
# define INITIAL_FOV 		45.0f
# define SPEED 				10.0f
# define ROTATION_ANGLE 	0.01f
# define KEY_COOLDOWN	 	0.8

# define LIGHT_POS_X	 	0
# define LIGHT_POS_Y	 	100
# define LIGHT_POS_Z	 	0

# include <stdio.h>

# define GLEW_NO_GLU
# include <glew.h>
# include <glfw3.h>
# include <OpenGL/gl.h>

# include "shader.h"
# include "libmath.h"
# include "libft.h"

typedef enum		e_mode
{
	MODE_COLOR,
	MODE_TEXTURE
}					t_mode;

typedef struct		s_env
{
	GLFWwindow		*window;
	t_vector		*position;
	t_mat			*mvp;
	double			last_time;
	t_mode			mode;
}					t_env;

void				init_env(t_env *env);
t_env				*get_env();

/*
** Create one opengl buffer.
*/
GLuint				gl_gen_buffer(GLenum target, GLsizeiptr size,
								GLvoid *data, GLenum usage);

/*
** Load a .bmp teture file.
*/
GLuint				load_bmp(const char *const imagepath);

typedef struct		s_mesh
{
	float			*vertices;
	float			*uvs;
	float			*normals;
	float			*colors;
	t_uint			size;
	GLuint			gl_buff_vertex;
	GLuint			gl_buff_uv;
	GLuint			gl_buff_colors;
	GLuint			gl_buff_normal;
	t_quaternion	*rotation;
	t_pt3f			position;
	float			scale;
}					t_mesh;

t_mesh				*load_mesh(char const *const path);
void				free_mesh(t_mesh *m);

/*
** Function which rotate the mesh.
*/
void				rotate_mesh(t_mesh *m);

t_mat				*model_matrix(t_mesh *mesh);
void				mvp_matrix();
void				key_handler(GLFWwindow *window, int key,
								int a, int b, int c);

typedef struct		s_uniform
{
	GLuint			color;
	GLuint			text;
}					t_uniform;

typedef struct		s_resources
{
	t_mesh			*mesh;
	t_mesh			*light_mesh;
	t_shader		*shader_color;
	t_shader		*shader_texture;
	GLuint			texture;
	t_uniform		gl_texture_uni;
	t_uniform		gl_mvp_uni;
	t_uniform		gl_model_uni;
	t_uniform		gl_lightpos_uni;
	t_uniform		gl_camera_uni;
	GLuint			vertex_array_id;
}					t_resources;

t_resources			*load_resources(int argc, char **argv);
void				free_resources(t_resources *res);

/*
** This function is displaying an object using opengl.
** The corresponding shader must has been launch and it accept vertices on
** location 0 and uv on location 1.
** size :		The number of float in the array (nb_vertices * 3).
** uniform_id:	The id of the glsl uniform in which to put the model matrix.
*/
void				gl_display_object(t_resources *res,
										t_mesh *mesh,
										t_mode mode);

#endif
