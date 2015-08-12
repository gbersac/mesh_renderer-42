/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:26:17 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/12 14:10:30 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int				test_header(unsigned char *header, FILE *file)
{
	if (fread(header, 1, 54, file) != 54)
	{
		printf("Not a correct BMP file\n");
		return (0);
	}
	if (header[0] != 'B' || header[1] != 'M')
	{
		printf("Not a correct BMP file\n");
		return (0);
	}
	return (1);
}

static GLuint			create_opengl_texture(t_uint width,
									t_uint height,
									unsigned char *data)
{
	GLuint	texture_id;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
			GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return (texture_id);
}

static GLuint			read_bmp(FILE *file, unsigned char *header)
{
	t_uint			data_pos;
	t_uint			image_size;
	unsigned char	*data;
	t_uint			width;
	t_uint			height;

	data_pos = *(int*)&(header[0x0A]);
	image_size = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (image_size == 0)
		image_size = width * height * 3;
	if (data_pos == 0)
		data_pos = 54;
	data = (unsigned char*)malloc(image_size * sizeof(unsigned char));
	fread(data, 1, image_size, file);
	fclose(file);
	return (create_opengl_texture(width, height, data));
}

GLuint					load_bmp(const char *const imagepath)
{
	unsigned char	header[54];
	FILE			*file;
	GLuint			texture_id;

	file = fopen(imagepath, "rb");
	if (!file)
	{
		printf("Image could not be opened\n");
		return (0);
	}
	if (!test_header(header, file))
		return (0);
	texture_id = read_bmp(file, header);
	return (texture_id);
}
