/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 17:41:31 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/24 16:00:46 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_identity(t_uint n)
{
	t_mat	*to_return;
	t_uint	i;

	if (n < 1)
		return (NULL);
	to_return = mat_new(n, n);
	mat_zero(to_return);
	i = 0;
	while (i < n)
	{
		mat_set(to_return, i + 1, i + 1, 1);
		++i;
	}
	return (to_return);
}
