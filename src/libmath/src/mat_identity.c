/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 17:41:31 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 13:38:40 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_identity(t_uint n)
{
	t_mat	*to_return;
	t_uint	i;

	to_return = mat_new(n, n);
	memset(to_return->array, 0, n * n * sizeof(t_mat_type));
	i = 0;
	while (i < n)
	{
		mat_set(to_return, i + 1, i + 1, 1);
		++i;
	}
	return (to_return);
}
