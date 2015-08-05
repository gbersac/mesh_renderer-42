/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/04 15:29:20 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/04 18:11:19 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			vec_set(t_vector *vec,
						t_uint idx,
						t_mat_type value,
						t_matrix_err *err)
{
	*err = mat_set(vec, 0, idx, value);
}
