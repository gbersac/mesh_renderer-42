/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 18:00:13 by gbersac           #+#    #+#             */
/*   Updated: 2015/08/09 18:33:13 by gbersac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_handler()
{
	static int	last_key_press = 0;
	t_env		*env;
	double		now;

	now = glfwGetTime( );
	if (now - last_key_press < KEY_COOLDOWN)
		return ;
	env = get_env();
	if (glfwGetKey(env->window, GLFW_KEY_M ) == GLFW_PRESS)
	{
		if (env->mode == MODE_COLOR)
			env->mode = MODE_TEXTURE;
		else if (env->mode == MODE_TEXTURE)
			env->mode = MODE_COLOR;
		last_key_press = now;
	}
}