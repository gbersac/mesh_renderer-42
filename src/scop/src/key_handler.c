/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 18:00:13 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/09 19:09:08 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_handler(GLFWwindow *window, int key, int a, int b, int c)
{
	static int	last_key_press = 0;
	t_env		*env;
	double		now;

	now = glfwGetTime();
	env = get_env();
	if (now - last_key_press < KEY_COOLDOWN)
		return ;
	if (key == GLFW_KEY_M)
	{
		if (env->mode == MODE_COLOR)
			env->mode = MODE_TEXTURE;
		else if (env->mode == MODE_TEXTURE)
			env->mode = MODE_COLOR;
		last_key_press = now;
	}
	window = NULL;
	a = 0;
	b = 0;
	c = 0;
}
