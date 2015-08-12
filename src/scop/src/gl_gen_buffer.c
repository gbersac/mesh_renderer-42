/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_gen_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 19:01:08 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:55:56 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint	gl_gen_buffer(GLenum target, GLsizeiptr size,
						GLvoid *data, GLenum usage)
{
	GLuint	to_return;

	glGenBuffers(1, &to_return);
	glBindBuffer(target, to_return);
	glBufferData(target, size, data, usage);
	return (to_return);
}
