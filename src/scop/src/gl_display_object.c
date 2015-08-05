/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:45:06 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 16:12:01 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	gl_display_object(t_mesh *mesh, GLuint uniform_id)
{
	// calculate the model matrix of this mesh and send it to opengl
	t_mat *model_mat = model_matrix(mesh);
	glUniformMatrix4fv(uniform_id, 1, GL_FALSE, model_mat->array);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->gl_buff_vertex);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : uv
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->gl_buff_uv);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Draw the mesh
	glDrawArrays(GL_TRIANGLES, 0, mesh->size);

	// free content
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	free(model_mat);
}
