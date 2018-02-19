/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:22:57 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 13:59:03 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_camera(t_wolf *wolf3d)
{
	wolf3d->height = 32;
	wolf3d->visual = 60;
	wolf3d->poscamx = 160;
	wolf3d->poscamy = 320;
	wolf3d->angle = 1;
	wolf3d->projector_length = 640;
	wolf3d->projector_height = 400;
	wolf3d->dist_projector = 320.0 / tan(30 * M_PI / 180);
}

void	init_wolf(t_wolf *wolf3d)
{
	int i;

	i = 64;
	wolf3d->mlx = mlx_init();
	wolf3d->win = mlx_new_window(wolf3d->mlx, 640, 400, "WOLF3D");
	wolf3d->byte = 4;
	wolf3d->line = 4 * 64;
	wolf3d->endian = 0;
	wolf3d->image_wall = mlx_xpm_file_to_image(wolf3d->mlx,\
			"bluew.xpm", &i, &i);
	wolf3d->data_wall = mlx_get_data_addr(wolf3d->image_wall,\
			&wolf3d->byte, &wolf3d->line, &wolf3d->endian);
	wolf3d->image_secret = mlx_xpm_file_to_image(wolf3d->mlx,\
			"redbrick.xpm", &i, &i);
	wolf3d->data_secret = mlx_get_data_addr(wolf3d->image_secret,\
			&wolf3d->byte, &wolf3d->line, &wolf3d->endian);
	wolf3d->line = 4 * 640;
}
