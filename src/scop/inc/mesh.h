/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 13:19:01 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:11:48 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "scop.h"

typedef struct	s_load_mesh_vars
{
	t_list		*uv_indices;
	t_list		*vertex_indices;
	t_list		*normal_indices;
	t_list		*temp_vertices;
	t_list		*temp_uvs;
	t_list		*temp_normals;
}				t_load_mesh_vars;

t_mesh			*generate_mesh(t_load_mesh_vars *vars);
void			print_mesh(t_mesh *mesh);
void			print_uint_list(t_list *array, t_uint size);
void			scan_face(t_load_mesh_vars *vars, FILE *file);
void			add_normals(t_mesh *mesh, size_t nb_vertice);
void			add_colors(t_mesh *mesh, size_t nb_vertice);
void			add_uvs(t_mesh *mesh, size_t nb_vertice);
void			free_vars(t_load_mesh_vars *vars);

#endif
