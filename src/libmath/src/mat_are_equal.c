/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_are_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 19:34:02 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/05 15:23:14 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int	mat_are_equal(t_mat *m1, t_mat *m2, t_mat_type diff)
{
	int		nb_cell;
	int		i;

	if (m1 == NULL || m2 == NULL)
		return (0);
	if (m1->width != m2->width || m1->height != m2->height)
		return (0);
	nb_cell = m1->width * m1->height;
	i = 0;
	diff = fabs(diff);
	if (diff < 0.000000000000001)
		diff = 0.000001;
	while (i < nb_cell)
	{
		if (fabs(m1->array[i] - m2->array[i]) > diff)
			return (0);
		++i;
	}
	return (1);
}
