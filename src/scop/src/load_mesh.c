/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 19:18:51 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:20:07 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static void	scan_vertice(t_list **temp_vertices, FILE *file)
{
	t_pt3f	pt;
	t_list	*newl;

	fscanf(file, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
	newl = ft_lstnew(&pt, sizeof(t_pt3f));
	ft_lstaddq(temp_vertices, newl);
}

static void	scan_normal(t_list **temp_normals, FILE *file)
{
	t_pt3f	pt;
	t_list	*newl;

	fscanf(file, "%f %f %f\n", &pt.x, &pt.y, &pt.z);
	newl = ft_lstnew(&pt, sizeof(t_pt3f));
	ft_clstaddq(temp_normals, newl);
}

static void	scan_uv(t_list **temp_uvs, FILE *file)
{
	t_pt2f		pt;
	t_list		*newl;

	fscanf(file, "%f %f\n", &pt.x, &pt.y);
	pt.y = pt.y;
	newl = ft_lstnew(&pt, sizeof(t_pt2f));
	ft_clstaddq(temp_uvs, newl);
}

static void	load_mesh_loop(FILE *file, t_load_mesh_vars *vars)
{
	char	line_header[128];
	int		res;
	char	stupid_buffer[1000];

	while (1)
	{
		res = fscanf(file, "%s", line_header);
		if (res == EOF)
			break ;
		if (strcmp(line_header, "v") == 0)
			scan_vertice(&vars->temp_vertices, file);
		else if (strcmp(line_header, "vt") == 0)
			scan_uv(&vars->temp_uvs, file);
		else if (strcmp(line_header, "vn") == 0)
			scan_normal(&vars->temp_normals, file);
		else if (strcmp(line_header, "f") == 0)
			scan_face(vars, file);
		else
		{
			fgets(stupid_buffer, 1000, file);
		}
	}
}

t_mesh		*load_mesh(char const *const path)
{
	t_mesh				*to_return;
	t_load_mesh_vars	vars;
	FILE				*file;

	file = fopen(path, "r");
	if (file == NULL)
	{
		printf("Impossible to open the file %s\n", path);
		return (NULL);
	}
	ft_bzero(&vars, sizeof(vars));
	vars.temp_vertices = 0;
	load_mesh_loop(file, &vars);
	to_return = generate_mesh(&vars);
	free_vars(&vars);
	return (to_return);
}
