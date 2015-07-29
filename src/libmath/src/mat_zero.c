/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 13:59:36 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/29 20:50:49 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			mat_zero(t_mat *dest)
{
	if (dest == NULL)
		return ;
	bzero(dest->array, dest->width * dest->height * sizeof(t_mat_type));
}
