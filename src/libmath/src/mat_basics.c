/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 15:40:29 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/27 13:40:37 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat		*mat_new(t_uint width, t_uint height)
{
	t_mat	*to_return;

	to_return = (t_mat*)malloc(sizeof(t_mat));
	to_return->array = malloc(width * height * sizeof(t_mat_type));
	to_return->width = width;
	to_return->height = height;
	return (to_return);
}

void		mat_free(t_mat **to_free)
{
	if (to_free == NULL || *to_free == NULL)
		return ;
	free((*to_free)->array);
	free(*to_free);
	*to_free = NULL;
}

void		mat_init(t_mat *dest, t_mat_type const *const src)
{
	memcpy(dest->array, src, dest->width * dest->height * sizeof(t_mat_type));
}
