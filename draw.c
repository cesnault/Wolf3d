/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:20:14 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 12:28:21 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	floor_draw(t_wolf *wolf3d, int y, int col)
{
	int floor;
	int index;

	floor = 0;
	while (floor < y)
	{
		index = col * 4 + floor * wolf3d->line - 4;
		wolf3d->data[index] = 0x23;
		wolf3d->data[index + 1] = 0x23;
		wolf3d->data[index + 2] = 0x23;
		floor++;
	}
}

void	wall_draw(t_wolf *wolf3d, int *y, int col, double ywall)
{
	int index_wall;
	int index;

	if (*y >= 0)
	{
		index_wall = wolf3d->trueoffset * 4 + (int)ywall * (64 * 4) - 4;
		index = col * 4 + *y * wolf3d->line - 4;
		wolf3d->data[index] = wolf3d->data_main[index_wall];
		wolf3d->data[index + 1] = wolf3d->data_main[index_wall + 1];
		wolf3d->data[index + 2] = wolf3d->data_main[index_wall + 2];
	}
}

void	roof_draw(t_wolf *wolf3d, int *y, int col)
{
	int index;

	while (*y < 400)
	{
		index = col * 4 + *y * wolf3d->line - 4;
		wolf3d->data[index] = 0x5A;
		wolf3d->data[index + 1] = 0x5A;
		wolf3d->data[index + 2] = 0x5A;
		*y += 1;
	}
}

void	draw(t_wolf *wolf3d, double distcorrect, int col)
{
	int		hauteur;
	int		y;
	int		ymax;
	double	wall;
	double	ywall;

	if (distcorrect == -1)
		return ;
	hauteur = (64 / distcorrect * wolf3d->dist_projector);
	y = 200 - (hauteur / 2);
	ymax = 200 + (hauteur / 2);
	wall = 64.0 / (double)(ymax - y);
	ywall = 0;
	floor_draw(wolf3d, y, col);
	y++;
	while (y < ymax && y < 400)
	{
		wall_draw(wolf3d, &y, col, ywall);
		ywall += wall;
		y += 1;
	}
	roof_draw(wolf3d, &y, col);
}
