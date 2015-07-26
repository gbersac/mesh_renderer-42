/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_ret.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 12:40:57 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/24 12:53:36 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_ret(t_matrix_err *error, t_matrix_err val)
{
	if (error != NULL)
		*error = val;
	return (NULL);
}
