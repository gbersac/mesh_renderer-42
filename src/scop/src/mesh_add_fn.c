/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_add_fn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 13:51:52 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:54:10 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "mesh.h"

void		add_colors(t_mesh *mesh, size_t nb_vertice)
{
	float	color;
	size_t	i;

	i = 0;
	srand(time(NULL));
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

void		add_uvs(t_mesh *mesh, size_t nb_vertice)
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
