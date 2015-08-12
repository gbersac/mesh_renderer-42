/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_add_normals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 19:00:50 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:22:15 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		vertice_in_triangle(t_pt3f *vert, float *triangle)
{
	int		to_return;

	to_return = !memcmp(vert, triangle, sizeof(t_pt3f)) ||
			!memcmp(vert, triangle + 3, sizeof(t_pt3f)) ||
			!memcmp(vert, triangle + 6, sizeof(t_pt3f));
	return (to_return);
}

static t_vector	*add_one_cross(t_vector *cross, t_vector *ttl_cross)
{
	t_vector	*buff;

	if (ttl_cross == NULL)
		ttl_cross = cross;
	else
	{
		buff = mat_add(ttl_cross, cross, NULL);
		mat_free(&ttl_cross);
		ttl_cross = buff;
	}
	return (ttl_cross);
}

static t_vector	*return_normal(float nb_use, t_vector *ttl_cross)
{
	if (ttl_cross != NULL && nb_use != 0)
	{
		mat_scalar_multi(ttl_cross, 1 / nb_use, NULL);
		vec_normalize(ttl_cross);
	}
	else
		return (NULL);
	return (ttl_cross);
}

static t_vector	*vertice_normal(t_pt3f *vert, t_mesh *mesh, size_t nb_vertice)
{
	t_vector	*ttl_cross;
	float		nb_use;
	t_vector	*cross;
	t_uint		i;

	i = 0;
	nb_use = 0;
	ttl_cross = NULL;
	while (i < nb_vertice)
	{
		if (vertice_in_triangle(vert, mesh->vertices + i * 3))
		{
			++nb_use;
			cross = vec_normal((t_pt3f*)(mesh->vertices + 3 * i),
					(t_pt3f*)(mesh->vertices + 3 * i + 3),
					(t_pt3f*)(mesh->vertices + 3 * i + 6));
			vec_normalize(cross);
			ttl_cross = add_one_cross(cross, ttl_cross);
		}
		++i;
	}
	return (return_normal(nb_use, ttl_cross));
}

void			add_normals(t_mesh *mesh,
							size_t nb_vertice)
{
	size_t		i;
	t_vector	*normal;

	i = 0;
	mesh->normals = (float*)malloc(nb_vertice * 3 * sizeof(float));
	while (i < nb_vertice)
	{
		normal = vertice_normal((t_pt3f*)mesh->vertices + i, mesh, nb_vertice);
		if (normal != NULL)
		{
			memcpy(mesh->normals + i * 3, normal->array, sizeof(t_pt3f));
			mat_free(&normal);
		}
		++i;
	}
}
