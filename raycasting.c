/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:29:00 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 12:38:55 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color_wall_1(t_wolf *wolf3d, int map[12][21])
{
	int x;
	int y;

	x = wolf3d->change.hori_x;
	y = wolf3d->change.hori_y;
	if (map[x / 64][y / 64] == 1)
	{
		wolf3d->image_main = wolf3d->image_wall;
		wolf3d->data_main = wolf3d->data_wall;
	}
	else
	{
		wolf3d->image_main = wolf3d->image_secret;
		wolf3d->data_main = wolf3d->data_secret;
	}
}

void	boucle_ray(t_wolf *wolf3d,\
		double raycast, int map[12][21], double decal)
{
	int		col;
	double	distcorrect;
	double	hori;
	double	verti;
	int		com;

	col = 0;
	com = 0;
	while (col <= 640)
	{
		hori = dda_hori(wolf3d, map, raycast);
		verti = dda_verti(wolf3d, map, raycast);
		hori_or_verti(hori, verti, &com);
		if (com == 1)
			hori_init(wolf3d, raycast, hori, &distcorrect);
		else if (com == 2)
			verti_init(wolf3d, raycast, verti, &distcorrect);
		else
			distcorrect = -1;
		color_main(wolf3d, com, map);
		draw(wolf3d, distcorrect, col);
		raycast += decal;
		col++;
	}
}
