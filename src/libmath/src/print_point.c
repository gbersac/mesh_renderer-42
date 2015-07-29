/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 16:36:35 by gbersac           #+#    #+#             */
/*   Updated: 2015/07/29 16:53:16 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	print_pt3f(t_pt3f *pt)
{
	printf("%f %f %f\n", pt->x, pt->y, pt->z);
}

void	print_pt2f(t_pt2f *pt)
{
	printf("%f %f\n", pt->x, pt->y);
}

void	print_pt3u(t_pt3u *pt)
{
	printf("%u %u %u\n", pt->x, pt->y, pt->z);
}

