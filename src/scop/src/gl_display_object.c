/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:45:06 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/29 19:15:49 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	gl_display_object(t_mesh *mesh)
{
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
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
