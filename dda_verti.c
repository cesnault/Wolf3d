/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_verti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:26:36 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 13:54:29 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check2(double *xa, double raycast, double *ya)
{
	if ((raycast < 90 && raycast > -90) || (raycast >= 270 && raycast <= 450))
		*xa = 64;
	else if (raycast < 270 && raycast > 90)
		*xa = -64;
	*ya = 64 * tan(raycast * M_PI / 180);
	if (raycast < 90 || raycast > 270)
		*ya *= -1;
}

double		check(double raycast, double *x, t_wolf *wolf3d, double *y)
{
	if (raycast == 90 || raycast == 270)
		return (20000);
	if ((raycast < 90 && raycast > -90) || (raycast > 270 && raycast <= 450))
		*x = (int)(wolf3d->poscamx / 64) * 64 + 64;
	else
		*x = (int)(wolf3d->poscamx / 64) * 64 - 1;
	*y = (wolf3d->poscamy + (wolf3d->poscamx - *x) * tan(raycast * M_PI / 180));
	return (0);
}

double		dda_verti(t_wolf *wolf3d, int map[12][21], double raycast)
{
	double	x;
	double	y;
	double	xa;
	double	ya;
	int		compteur;

	compteur = 0;
	xa = 0;
	if ((check(raycast, &x, wolf3d, &y) == 20000))
		return (20000);
	check2(&xa, raycast, &ya);
	while (compteur == 0)
	{
		if (X / 64 < 0 || Y / 64 < 0 || X / 64 > 11 || Y / 64 > 20)
			compteur = 1;
		else if (map[X / 64][Y / 64] == 1 || map[X / 64][Y / 64] == 2)
			compteur = 1;
		else
			incr(&x, &y, &xa, &ya);
	}
	wolf3d->offsetverti = (int)y % 64;
	wolf3d->change.verti_x = x;
	wolf3d->change.verti_y = y;
	return (fabs(wolf3d->poscamx - (x)) / fabs(cos(raycast * M_PI / 180)));
}
