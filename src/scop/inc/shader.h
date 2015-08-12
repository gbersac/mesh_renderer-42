/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 13:42:55 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 13:43:14 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# define GL3_PROTOTYPES 1
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_shader
{
	GLuint		vertex_id;
	GLuint		fragment_id;
	GLuint		program_id;
}				t_shader;

t_shader		*load_shader(const char *vertex_src, const char *fragment_src);

#endif
