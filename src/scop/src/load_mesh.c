/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 19:18:51 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 17:20:11 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"


void	scan_vertice(t_list **temp_vertices, FILE *file)
{
	t_pt3f	pt;
	t_list	*newl;

	fscanf(file, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
	newl = ft_lstnew(&pt, sizeof(t_pt3f));
	ft_lstaddq(temp_vertices, newl);
}

void	scan_normal(t_list **temp_normals, FILE *file)
{
	t_pt3f	pt;
	t_list	*newl;

	fscanf(file, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
	newl = ft_lstnew(&pt, sizeof(t_pt3f));
	ft_clstaddq(temp_normals, newl);
}

void	scan_uv(t_list **temp_uvs, FILE *file)
{
	t_pt2f		pt;
	t_list		*newl;

	fscanf(file, "%f %f\n", &pt.x, &pt.y);
	pt.y = -pt.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
	newl = ft_lstnew(&pt, sizeof(t_pt2f));
	ft_clstaddq(temp_uvs, newl);
}

void	pface(t_list **dst, t_list *src, t_uint idx, size_t size)
{
	void	*model;

	model = ft_lst_get(src, idx);
	ft_push_back(dst, model, size);
}

void	free_vars(t_load_mesh_vars *vars)
{
	ft_lstdel(&vars->uv_indices, free);
	ft_lstdel(&vars->vertex_indices, free);
	ft_lstdel(&vars->normal_indices, free);
	ft_lstdel(&vars->temp_vertices, free);
	// ft_lstdel(&vars->temp_uvs, free);
	// ft_lstdel(&vars->temp_normals, free);
}

void	print_mesh_points(float *array, t_uint size, t_uint increment)
{
	t_uint	i;

	i = 0;
	while (i < size)
	{
		if (increment == 2)
			printf("%f %f\n", *(array + i * 2), *(array + i * 2 + 1));
		if (increment == 3)
			printf("%f %f %f\n", *(array + i * 3),
					*(array + i * 3 + 1),
					*(array + i * 3 + 2));
		++i;
	}
}

void	print_mesh(t_mesh *mesh)
{
	printf("\tvertices\n");
	print_mesh_points(mesh->vertices, mesh->size, 3);
	printf("\n\tuvs\n");
	print_mesh_points(mesh->uvs, mesh->size, 2);
	printf("\n\tnormals\n");
	print_mesh_points(mesh->normals, mesh->size, 3);
}

t_mesh	*load_mesh(char const * const path)
{
	t_mesh			*to_return;
	t_load_mesh_vars	vars;

	FILE * file = fopen(path, "r");
	if(file == NULL)
	{
		printf("Impossible to open the file %s\n", path);
		return NULL;
	}
	ft_bzero(&vars, sizeof(vars));
	vars.temp_vertices = 0;
	while(1)
	{
		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break ;
		if (strcmp(lineHeader, "v") == 0)
			scan_vertice(&vars.temp_vertices, file);
		else if (strcmp(lineHeader, "vt") == 0)
			scan_uv(&vars.temp_uvs, file);
		else if (strcmp(lineHeader, "vn") == 0)
			scan_normal(&vars.temp_normals, file);
		else if (strcmp(lineHeader, "f") == 0)
			scan_face(&vars, file);
		else
		{
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}
	to_return = generate_mesh(&vars);
	free_vars(&vars);
	return(to_return);
}
