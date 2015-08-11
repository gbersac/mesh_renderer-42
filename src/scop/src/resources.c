/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 19:36:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/11 15:33:40 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			free_resources(t_resources *res)
{
	glDeleteProgram(res->shader_color->program_id);
	glDeleteProgram(res->shader_texture->program_id);
	glDeleteVertexArrays(1, &res->vertex_array_id);
	free_mesh(res->mesh);
	glDeleteTextures(1, &res->texture);
}

// static t_mesh	*load_and_bind_mesh(char const *path, GLuint shader, char *name)
// {
// 	t_mesh	*to_return;

// 	to_return = load_mesh(path);
// 	to_return->gl_uniform = glGetUniformLocation(shader, name);
// 	return (to_return);
// }

t_mesh         *load_the_mesh(int argc, char **argv)
{
	t_mesh  *to_return;

	if (argc < 2)
	{
		printf("Usage : ./scop path_to_obj_file\n");
		return (NULL);
	}
	printf("Loading object %s\n", argv[1]);
	to_return = load_mesh(argv[1]);
	return (to_return);
}

static int		load_all_shaders(t_resources *res)
{
	res->shader_color = load_shader("src/shaders/simple_transf_color.vert",
			"src/shaders/color.frag");
	res->shader_texture = load_shader("src/shaders/simple_transf_texture.vert",
			"src/shaders/texture.frag");
	if (res->shader_color == NULL || res->shader_texture == NULL)
	{
		printf("Error shader construction\n");
		return (1);
	}
	return (0);
}

// static t_mesh	*load_light_mesh()
// {
// 	t_mesh	*to_return;

// 	to_return = load_mesh("resources/cube.obj");
// 	to_return->position.x = -1;
// 	to_return->position.y = 0.5;
// 	to_return->position.z = -3;
// 	to_return->scale = 0.01;
// 	return (to_return);
// }

static GLuint	get_uniform(t_resources *res, char const * str)
{
	GLuint	to_return;

	to_return = glGetUniformLocation(res->shader_texture->program_id, str);
	return (to_return);

}

t_resources		*load_resources(int argc, char **argv)
{
	t_resources	*res;

	res = (t_resources*)malloc(sizeof(t_resources));
	if (load_all_shaders(res))
		return (NULL);
	res->mesh = load_the_mesh(argc, argv);
	// res->light_mesh = load_light_mesh();
	if (res->mesh == NULL || res->light_mesh == NULL)
		return (NULL);
	glGenVertexArrays(1, &res->vertex_array_id);
	glBindVertexArray(res->vertex_array_id);
	res->texture = load_bmp("resources/uvtemplate.bmp");
	res->texture_id  = get_uniform(res, "TEXTURE_UNIFORM");
	res->gl_mvp_uni = get_uniform(res, "MVP");
	res->gl_model_uni = get_uniform(res, "MODEL");
	res->gl_lightpos_uni = get_uniform(res, "LIGHT_POSITION");
	res->gl_camera_uni = get_uniform(res, "CAMERA_POSITION");
	return(res);
}
