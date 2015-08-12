/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:24:29 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:27:55 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat			*mat_cpy(t_mat const *const to_cpy)
{
	t_mat	*to_return;

	if (to_cpy == NULL)
		return (NULL);
	to_return = mat_new(to_cpy->width, to_cpy->height);
	memcpy(to_return->array, to_cpy->array,
			to_cpy->width * to_cpy->height * sizeof(t_mat_type));
	return (to_return);
}
