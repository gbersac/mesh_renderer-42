/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_subst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:41:53 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:34:34 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	subst(t_mat *dest,
				t_mat const *const m1,
				t_mat const *const m2)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (i < dest->width)
	{
		j = 0;
		while (j < dest->height)
		{
			mat_set(dest, j, i,
					mat_get(m1, j, i, NULL) -
					mat_get(m2, j, i, NULL));
			++j;
		}
		++i;
	}
}

t_mat	*mat_subst(t_mat const *const m1, t_mat const *const m2,
					t_matrix_err *err)
{
	t_mat	*to_return;

	if (m1 == NULL || m2 == NULL)
		return (mat_ret(err, NO_ERROR));
	if (m1->width != m2->width || m1->height != m1->height)
		return (mat_ret(err, INCOMPATIBLE_SIZE));
	to_return = mat_new(m1->width, m1->height);
	subst(to_return, m1, m2);
	return (to_return);
}
