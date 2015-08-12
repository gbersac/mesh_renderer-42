/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 17:08:05 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 18:19:11 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat				*model_matrix(t_mesh *mesh)
{
	static t_mat	*scaling = NULL;
	static t_mat	*translation = NULL;
	t_mat			*rotation;
	t_mat			*to_return;
	t_mat			*buff;

	rotation = quat_to_matrix(mesh->rotation);
	scaling = mat_diagonal(scaling, 4, mesh->scale);
	translation = mat_translation(translation, mesh->position);
	buff = mat_multi(translation, rotation, NULL);
	to_return = mat_multi(buff, scaling, NULL);
	mat_free(&rotation);
	mat_free(&buff);
	return (to_return);
}
