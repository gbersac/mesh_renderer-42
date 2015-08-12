/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 16:36:58 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:33:39 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			print_line(t_mat const *const m, t_uint line)
{
	t_uint	i;

	i = 0;
	while (i < m->width)
	{
		if (i != 0)
			printf(", ");
		printf("%f", mat_get(m, line, i, NULL));
		++i;
	}
	printf("\n");
}

void			mat_print(t_mat const *const m)
{
	mat_print_label(m, "");
}

void			mat_print_label(t_mat const *const m, char const *const label)
{
	t_uint	i;

	if (m == NULL)
	{
		printf("Matrix NULL %s\n", label);
		return ;
	}
	printf("Matrix[%u, %u] %s\n", m->height, m->width, label);
	i = 0;
	while (i < m->height)
	{
		print_line(m, i);
		++i;
	}
}
