/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_hori.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:25:11 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 13:55:50 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check4(double *xa, double raycast, double *ya)
{
	if ((raycast < 180 && raycast > 0) || (raycast > 360 && raycast < 540))
		*ya = -64;
	else if ((raycast > 180 && raycast < 360) || raycast < 0)
		*ya = 64;
	*xa = 64 / tan(raycast * M_PI / 180);
	if ((raycast < 360 && raycast > 180) || raycast < 0)
		*xa *= -1;
}

double		check3(double raycast, double *x, t_wolf *wolf3d, double *y)
{
	if (raycast == 180 || raycast == 0)
		return (20000);
	if ((raycast < 180 && raycast > 0) || (raycast > 360 && raycast < 540))
		*y = (int)(wolf3d->poscamy / 64) * 64 - 1;
	else
		*y = (int)(wolf3d->poscamy / 64) * 64 + 64;
	*x = wolf3d->poscamx + (wolf3d->poscamy - (*y)) / tan(raycast * M_PI / 180);
	return (0);
}

void		incr(double *x, double *y, double *xa, double *ya)
{
	*x += *xa;
	*y += *ya;
}

double		dda_hori(t_wolf *wolf3d, int map[12][21], double raycast)
{
	double	x;
	double	y;
	double	xa;
	double	ya;
	int		compteur;

	compteur = 0;
	ya = 0;
	if (check3(raycast, &x, wolf3d, &y) == 20000)
		return (20000);
	check4(&xa, raycast, &ya);
	while (compteur == 0)
	{
		if (X / 64 < 0 || Y / 64 < 0 || X / 64 > 11 || Y / 64 > 20)
			compteur = 1;
		else if (map[X / 64][Y / 64] == 1 || map[X / 64][Y / 64] == 2)
			compteur = 1;
		else
			incr(&x, &y, &xa, &ya);
	}
	wolf3d->offsethori = (int)x % 64;
	wolf3d->change.hori_x = x;
	wolf3d->change.hori_y = y;
	return (fabs(wolf3d->poscamx - (x)) / fabs(cos(raycast * M_PI / 180)));
}
