/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:45:06 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/09 17:41:11 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	bind_buffer(GLuint buffer, GLuint idx, GLuint size)
{
	glEnableVertexAttribArray(idx);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(idx, size, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void	gl_display_object(t_mesh *mesh, GLuint uniform_id)
{
	t_env	*env;

	env = get_env();
	t_mat *model_mat = model_matrix(mesh);
	glUniformMatrix4fv(uniform_id, 1, GL_FALSE, model_mat->array);
	bind_buffer(mesh->gl_buff_vertex, 0, 3);
	if (env->mode == MODE_COLOR)
		bind_buffer(mesh->gl_buff_colors, 1, 3);
	else
		bind_buffer(mesh->gl_buff_uv, 1, 2);
	glDrawArrays(GL_TRIANGLES, 0, mesh->size);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	free(model_mat);
}
