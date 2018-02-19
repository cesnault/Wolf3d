/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:27:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 12:41:06 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_correct(t_wolf *wolf3d, double fish, double raycast)
{
	double distcorrect;

	(void)raycast;
	(void)wolf3d;
	distcorrect = fish;
	if (fish == -1)
		return (fish);
	distcorrect = fish * cos((raycast - wolf3d->angle) * M_PI / 180);
	return (distcorrect);
}
