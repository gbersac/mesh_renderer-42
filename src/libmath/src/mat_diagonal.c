/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_diagonal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:29:00 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 18:07:34 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_diagonal(t_mat *mat, t_uint n, float val)
{
	t_uint	i;

	if (mat == NULL)
		mat = mat_new(n, n);
	if (mat->width != n || mat->height != n)
		return (NULL);
	mat_zero(mat);
	i = 0;
	while (i < n)
	{
		mat_set(mat, i, i, val);
		++i;
	}
	return (mat);
}
