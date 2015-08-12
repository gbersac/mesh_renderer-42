/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:45:06 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:55:33 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		bind_buffer(GLuint buffer, GLuint idx, GLuint size)
{
	glEnableVertexAttribArray(idx);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(idx, size, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

static GLuint	get_uniform_id(t_uniform *uni, t_mode mode)
{
	if (mode == MODE_COLOR)
		return (uni->color);
	return (uni->text);
}

static void		set_uniform(t_resources *res, t_mode mode)
{
	t_pt3f	*camera;

	camera = (t_pt3f*)get_env()->position->array;
	glUniformMatrix4fv(get_uniform_id(&res->gl_mvp_uni, mode),
			1, GL_FALSE, get_env()->mvp->array);
	glUniform3f(get_uniform_id(&res->gl_lightpos_uni, mode),
			LIGHT_POS_X, LIGHT_POS_Y, LIGHT_POS_Z);
	glUniform3f(get_uniform_id(&res->gl_camera_uni, mode),
			camera->x, camera->y, camera->z);
}

void			gl_display_object(t_resources *res, t_mesh *mesh, t_mode mode)
{
	t_mat	*model_mat;

	set_uniform(res, mode);
	if (mode == MODE_COLOR)
		glUseProgram(res->shader_color->program_id);
	else
		glUseProgram(res->shader_texture->program_id);
	model_mat = model_matrix(mesh);
	glUniformMatrix4fv(get_uniform_id(&res->gl_model_uni, mode),
			1, GL_FALSE, model_mat->array);
	bind_buffer(mesh->gl_buff_vertex, 0, 3);
	if (mode == MODE_COLOR)
		bind_buffer(mesh->gl_buff_colors, 1, 3);
	else
		bind_buffer(mesh->gl_buff_uv, 1, 2);
	bind_buffer(mesh->gl_buff_normal, 2, 3);
	glDrawArrays(GL_TRIANGLES, 0, mesh->size);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	free(model_mat);
}
