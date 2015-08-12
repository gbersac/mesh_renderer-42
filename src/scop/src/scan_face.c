/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_face.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:40:08 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:47:01 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static void	scan_with_uv_normal(t_load_mesh_vars *vars,
								t_pt4u vi, t_pt3u uvi, t_pt3u ni)
{
	ft_push_back(&vars->vertex_indices, &vi.x, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.y, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.z, sizeof(t_uint));
	ft_push_back(&vars->uv_indices, &uvi.x, sizeof(t_uint));
	ft_push_back(&vars->uv_indices, &uvi.y, sizeof(t_uint));
	ft_push_back(&vars->uv_indices, &uvi.z, sizeof(t_uint));
	ft_push_back(&vars->normal_indices, &ni.x, sizeof(t_uint));
	ft_push_back(&vars->normal_indices, &ni.y, sizeof(t_uint));
	ft_push_back(&vars->normal_indices, &ni.z, sizeof(t_uint));
}

static void	scan_vertice_only(t_load_mesh_vars *vars, t_pt4u vi)
{
	ft_push_back(&vars->vertex_indices, &vi.x, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.y, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.z, sizeof(t_uint));
}

static void	scan_vertice_only_square(t_load_mesh_vars *vars, t_pt4u vi)
{
	ft_push_back(&vars->vertex_indices, &vi.x, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.y, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.z, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.x, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.z, sizeof(t_uint));
	ft_push_back(&vars->vertex_indices, &vi.w, sizeof(t_uint));
}

void		scan_face(t_load_mesh_vars *vars, FILE *file)
{
	t_pt4u	vi;
	t_pt3u	uvi;
	t_pt3u	ni;
	int		matches;
	char	buffer[300];

	fgets(buffer, 300, file);
	matches = sscanf(buffer, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
			&vi.x, &uvi.x, &ni.x, &vi.y, &uvi.y, &ni.y, &vi.z, &uvi.z, &ni.z);
	if (matches == 9)
		scan_with_uv_normal(vars, vi, uvi, ni);
	else
	{
		matches = sscanf(buffer, "%d %d %d %d\n", &vi.x, &vi.y, &vi.z, &vi.w);
		if (matches == 4)
		{
			scan_vertice_only_square(vars, vi);
			return ;
		}
		matches = sscanf(buffer, "%d %d %d\n", &vi.x, &vi.y, &vi.z);
		if (matches != 3)
			printf("Error : line can't be read\n");
		else
			scan_vertice_only(vars, vi);
	}
}
