/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mesh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 14:53:39 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 17:25:16 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static t_mesh	*init_mesh(size_t nb_vertice, t_load_mesh_vars *vars)
{
	t_mesh	*to_return;

	to_return = (t_mesh*)malloc(sizeof(t_mesh));
	bzero(to_return, sizeof(t_mesh));
	to_return->vertices = (float*)malloc(nb_vertice * 3 * sizeof(float));
	to_return->colors = (float*)malloc(nb_vertice * 9 * sizeof(float));
	if (ft_lstlen(vars->uv_indices) != 0)
		to_return->uvs = (float*)malloc(
				ft_lstlen(vars->uv_indices) * 2 * sizeof(float));
	to_return->normals = (float*)malloc(
			ft_lstlen(vars->normal_indices) * 3 * sizeof(float));
	to_return->size = nb_vertice;
	to_return->rotation = vec_new(4);
	mat_zero(to_return->rotation);
	((t_pt4f*)to_return->rotation->array)->w = 1;
	to_return->scale = 1;
	return (to_return);
}

static void		fill_mesh(t_mesh *mesh,
							t_load_mesh_vars *vars,
							size_t nb_vertice)
{
	t_uint		*vertex_index;
	t_uint		*uv_index;
	t_uint		*normal_index;
	size_t		i;

	i = 0;
	while (i < nb_vertice)
	{
		vertex_index = (t_uint*)ft_lst_get(vars->vertex_indices, i);
		uv_index = (t_uint*)ft_lst_get(vars->uv_indices, i);
		normal_index = (t_uint*)ft_lst_get(vars->normal_indices, i);
		memcpy(mesh->vertices + i * 3,
				ft_lst_get(vars->temp_vertices, *vertex_index - 1),
				sizeof(t_pt3f));
		if (uv_index != NULL)
			memcpy(mesh->uvs + i * 2,
					ft_lst_get(vars->temp_uvs, *uv_index - 1),
					sizeof(t_pt2f));
		if (normal_index != NULL)
			memcpy(mesh->normals + i * 3,
					ft_lst_get(vars->temp_normals, *normal_index - 1),
					sizeof(t_pt3f));
		++i;
	}
}

static void		create_gl_buff(t_mesh *mesh)
{
	mesh->gl_buff_vertex = gl_gen_buffer(GL_ARRAY_BUFFER,
			mesh->size * sizeof(t_pt3f),
			(void*)mesh->vertices,
			GL_STATIC_DRAW);
	mesh->gl_buff_uv = gl_gen_buffer(GL_ARRAY_BUFFER,
			mesh->size * sizeof(t_pt3f),
			(void*)mesh->uvs,
			GL_STATIC_DRAW);
	mesh->gl_buff_colors = gl_gen_buffer(GL_ARRAY_BUFFER,
			mesh->size * sizeof(t_pt3f),
			(void*)mesh->colors,
			GL_STATIC_DRAW);
}

static void		add_colors(t_mesh *mesh, size_t nb_vertice)
{
	float	color;
	size_t	i;

	i = 0;
	while (i < nb_vertice)
	{
		color = ((float)rand() / RAND_MAX);
		memcpy(mesh->colors + i * 9 + 0, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 1, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 2, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 3, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 4, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 5, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 6, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 7, &color, sizeof(float));
		memcpy(mesh->colors + i * 9 + 8, &color, sizeof(float));
		++i;
	}
}

static void		add_uvs(t_mesh *mesh, size_t nb_vertice)
{
	size_t	i;
	t_pt3f	*vertice;

	mesh->uvs = (float*)malloc(nb_vertice * 2 * sizeof(float));
	i = 0;
	while (i < nb_vertice)
	{
		vertice = (t_pt3f*)(mesh->vertices + 3 * i);
		memcpy(mesh->uvs + i * 2 + 0, &vertice->x, sizeof(float));
		memcpy(mesh->uvs + i * 2 + 1, &vertice->y, sizeof(float));
		++i;
	}
}

t_mesh			*generate_mesh(t_load_mesh_vars *vars)
{
	size_t		nb_vertice;
	t_mesh		*to_return;

	nb_vertice = ft_lstlen(vars->vertex_indices);
	to_return = init_mesh(nb_vertice, vars);
	fill_mesh(to_return, vars, nb_vertice);
	add_colors(to_return, nb_vertice);
	if (to_return->uvs == NULL)
		add_uvs(to_return, nb_vertice);
	create_gl_buff(to_return);
	return (to_return);
}
