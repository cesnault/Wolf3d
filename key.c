/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:24:14 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 13:44:55 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	forward_backward(int keycode, void *param)
{
	if (keycode == 126)
	{
		if (ANGLE > 180 && ANGLE < 360)
			CAMY += -10 * sin(ANGLE * M_PI / 180.0);
		else
			CAMY += -10 * sin(ANGLE * M_PI / 180.0);
		if (((t_wolf *)param)->angle < 180)
			CAMX += 10 * cos(ANGLE * M_PI / 180.0);
		else
			CAMX += 10 * cos(ANGLE * M_PI / 180.0);
	}
	if (keycode == 125)
	{
		if (ANGLE > 180 && ANGLE < 360)
			CAMY += 10 * sin(ANGLE * M_PI / 180.0);
		else
			CAMY += 10 * sin(ANGLE * M_PI / 180.0);
		if (ANGLE < 180)
			CAMX += -10 * cos(ANGLE * M_PI / 180.0);
		else
			CAMX += -10 * cos(ANGLE * M_PI / 180.0);
	}
}

int		key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		if (((t_wolf *)param)->angle == 0)
			((t_wolf *)param)->angle = 359;
		else
			((t_wolf *)param)->angle -= 1;
	}
	if (keycode == 124)
	{
		if (((t_wolf *)param)->angle == 359)
			((t_wolf *)param)->angle = 0;
		else
			((t_wolf *)param)->angle += 1;
	}
	forward_backward(keycode, param);
	raycasting((t_wolf *)param);
	return (0);
}
