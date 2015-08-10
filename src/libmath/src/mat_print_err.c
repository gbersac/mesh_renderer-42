/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_print_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:59:16 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/10 18:02:45 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	mat_print_error(t_matrix_err err)
{
	if (err == NO_MATRIX)
		puts("Matrice error : NO_MATRIX\n");
	if (err == OUT_OF_BOUND)
		puts("Matrice error : OUT_OF_BOUND\n");
	if (err == INCOMPATIBLE_SIZE)
		puts("Matrice error : INCOMPATIBLE_SIZE\n");
}
