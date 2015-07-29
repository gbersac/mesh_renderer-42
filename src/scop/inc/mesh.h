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

t_mesh	*generate_mesh(t_load_mesh_vars *vars);
void	print_mesh(t_mesh *mesh);
void	print_uint_list(t_list *array, t_uint size);

#endif
