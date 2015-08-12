/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:35:42 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:34:43 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat	*mat_translation(t_mat *dest, t_pt3f direction)
{
	if (dest == NULL)
		dest = mat_new(4, 4);
	mat_zero(dest);
	mat_set(dest, 0, 0, 1);
	mat_set(dest, 1, 1, 1);
	mat_set(dest, 2, 2, 1);
	mat_set(dest, 3, 3, 1);
	mat_set(dest, 3, 0, direction.x);
	mat_set(dest, 3, 1, direction.y);
	mat_set(dest, 3, 2, direction.z);
	return (dest);
}
