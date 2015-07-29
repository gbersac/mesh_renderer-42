/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mesh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 14:53:39 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/29 21:40:28 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static t_mesh	*init_mesh(size_t nb_vertice)
{
	t_mesh	*to_return;

	to_return = (t_mesh*)malloc(sizeof(t_mesh));
	to_return->vertices = (float*)malloc(nb_vertice * 3 * sizeof(float));
	to_return->uvs = (float*)malloc(nb_vertice * 2 * sizeof(float));
	to_return->normals = (float*)malloc(nb_vertice * 3 * sizeof(float));
	to_return->size = nb_vertice;
	return (to_return);
}

void	print_uint_list(t_list *array, t_uint size)
{
	t_uint k = 0;
	while (array != NULL)
	{
		t_uint		*veridx = (t_uint *)array->content;
		if (veridx != NULL)
			printf("a[%u] %u ", k, *veridx);
		array = array->next;
		++k;
	}
	printf("\n");
	size = 0;
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
		memcpy(mesh->uvs + i * 2,
				ft_lst_get(vars->temp_uvs, *uv_index - 1),
				sizeof(t_pt2f));
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
}

t_mesh			*generate_mesh(t_load_mesh_vars *vars)
{
	size_t		nb_vertice;
	t_mesh		*to_return;

	nb_vertice = ft_lstlen(vars->vertex_indices);
	to_return = init_mesh(nb_vertice);
	fill_mesh(to_return, vars, nb_vertice);
	// print_mesh(to_return);
	create_gl_buff(to_return);
	return (to_return);
}
