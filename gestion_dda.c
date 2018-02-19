/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:15:24 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 12:47:31 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color_wall_2(t_wolf *wolf3d, int map[12][21])
{
	int x;
	int y;

	x = wolf3d->change.verti_x;
	y = wolf3d->change.verti_y;
	if (map[x / 64][y / 64] == 1)
	{
		wolf3d->image_main = wolf3d->image_wall;
		wolf3d->data_main = wolf3d->data_wall;
	}
	else if (map[x / 64][y / 64] == 2)
	{
		wolf3d->image_main = wolf3d->image_secret;
		wolf3d->data_main = wolf3d->data_secret;
	}
}

void	color_main(t_wolf *wolf3d, int com, int map[12][21])
{
	if (com == 1)
	{
		color_wall_1(wolf3d, map);
	}
	else if (com == 2)
	{
		color_wall_2(wolf3d, map);
	}
}

void	hori_init(t_wolf *wolf3d,\
		double raycast, double hori, double *distcorrect)
{
	wolf3d->trueoffset = wolf3d->offsethori;
	*distcorrect = ft_correct(wolf3d, hori, raycast);
}

void	verti_init(t_wolf *wolf3d,\
		double raycast, double verti, double *distcorrect)
{
	wolf3d->trueoffset = wolf3d->offsetverti;
	*distcorrect = ft_correct(wolf3d, verti, raycast);
}

void	hori_or_verti(double hori, double verti, int *com)
{
	if ((hori <= verti && hori > 0))
	{
		*com = 1;
	}
	else if (verti > 0)
		*com = 2;
}
