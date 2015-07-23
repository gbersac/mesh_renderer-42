/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 13:59:36 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/23 14:14:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void			mat_zero(t_mat *dest)
{
	bzero(dest->array, dest->width * dest->height * sizeof(t_mat_type));
}
