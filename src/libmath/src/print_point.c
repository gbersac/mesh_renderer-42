/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 16:36:35 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:34:55 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	print_pt4f(t_pt4f *pt)
{
	printf("%f %f %f %f", pt->x, pt->y, pt->z, pt->w);
}

void	print_pt3f(t_pt3f *pt)
{
	printf("%f %f %f", pt->x, pt->y, pt->z);
}

void	print_pt2f(t_pt2f *pt)
{
	printf("%f %f", pt->x, pt->y);
}

void	print_pt3u(t_pt3u *pt)
{
	printf("%u %u %u", pt->x, pt->y, pt->z);
}
