/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 20:03:09 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/09 20:12:26 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		free_mesh(t_mesh *m)
{
	free(m->vertices);
	free(m->uvs);
	free(m->normals);
	free(m->colors);
	free(m->rotation);
}
