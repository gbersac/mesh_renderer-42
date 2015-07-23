/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 16:36:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 13:56:33 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			print_line(t_mat *m, t_uint line)
{
	t_uint	i;

	i = 0;
	while (i < m->width)
	{
		if (i != 0)
			printf(", ");
		printf("%f", mat_get(m, i + 1, line + 1, NULL));
		++i;
	}
	printf("\n");
}

void			mat_print(t_mat *m)
{
	mat_print_label(m, "");
}

void			mat_print_label(t_mat *m, char const * const label)
{
	t_uint	i;

	if (m == NULL)
	{
		printf("Matrix NULL %s\n", label);
		return ;
	}
	printf("Matrix[%u, %u] %s\n", m->width, m->height, label);
	i = 0;
	while (i < m->height)
	{
		print_line(m, i);
		++i;
	}
}

