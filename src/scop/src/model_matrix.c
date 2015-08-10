/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 17:08:05 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 16:04:46 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat				*model_matrix(t_mesh *mesh)
{
	t_mat			*to_return;

	to_return = quat_to_matrix(mesh->rotation);
	return(to_return);
}
