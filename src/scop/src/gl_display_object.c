/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:45:06 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/11 15:33:18 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		bind_buffer(GLuint buffer, GLuint idx, GLuint size)
{
	glEnableVertexAttribArray(idx);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(idx, size, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

static void		set_uniform(t_resources *res)
{
	t_pt3f	*camera;

	camera = (t_pt3f*)get_env()->position->array;
	glUniformMatrix4fv(res->gl_mvp_uni, 1, GL_FALSE, get_env()->mvp->array);
	glUniform3f(res->gl_lightpos_uni, LIGHT_POS_X, LIGHT_POS_Y, LIGHT_POS_Z);
	glUniform3f(res->gl_camera_uni, camera->x, camera->y, camera->z);
}

void			gl_display_object(t_resources *res, t_mesh *mesh, t_mode mode)
{
	set_uniform(res);
	if (mode == MODE_COLOR)
		glUseProgram(res->shader_color->program_id);
	else
		glUseProgram(res->shader_texture->program_id);
	t_mat *model_mat = model_matrix(mesh);
	glUniformMatrix4fv(res->gl_model_uni, 1, GL_FALSE, model_mat->array);
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
