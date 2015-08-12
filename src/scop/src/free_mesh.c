/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 20:03:09 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:18:02 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

void		free_mesh(t_mesh *m)
{
	free(m->vertices);
	free(m->uvs);
	free(m->normals);
	free(m->colors);
	free(m->rotation);
}

void		free_vars(t_load_mesh_vars *vars)
{
	ft_lstdel(&vars->uv_indices, free);
	ft_lstdel(&vars->vertex_indices, free);
	ft_lstdel(&vars->normal_indices, free);
	ft_lstdel(&vars->temp_vertices, free);
}
