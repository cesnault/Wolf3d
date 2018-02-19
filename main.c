/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:33:48 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 12:37:03 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_ajout(int map[12][21], int i, int j)
{
	if (i == 0 || i == 11)
		map[i][j] = 1;
	else if (j == 0 || j == 20)
		map[i][j] = 1;
	else if (i % 2 == 0 && j % 3 == 0)
		map[i][j] = 2;
	else if (i % 3 == 0 && j % 2 == 0)
		map[i][j] = 1;
	else
		map[i][j] = 0;
}

void	create_map(int map[12][21])
{
	int i;
	int j;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 21)
		{
			map_ajout(map, i, j);
			j++;
		}
		i++;
	}
}

void	raycasting(t_wolf *wolf3d)
{
	double	raycast;
	double	decal;
	int		map[12][21];

	decal = 60.0 / 640.0;
	create_map(map);
	wolf3d->image = mlx_new_image(wolf3d->mlx, 640, 400);
	wolf3d->data = mlx_get_data_addr(wolf3d->image,\
			&wolf3d->byte, &wolf3d->line, &wolf3d->endian);
	raycast = wolf3d->angle - 30;
	boucle_ray(wolf3d, raycast, map, decal);
	mlx_put_image_to_window(wolf3d->mlx, wolf3d->win, wolf3d->image, 0, 0);
	mlx_destroy_image(wolf3d->mlx, wolf3d->image);
	mlx_hook(wolf3d->win, 2, (1L << 0), &key, wolf3d);
	mlx_hook(wolf3d->win, 17, 1L << 17, red_cross, wolf3d);
	mlx_loop(wolf3d->mlx);
}

int		main(void)
{
	t_wolf	wolf3d;

	system("afplay ./Get_them.mp3&");
	init_wolf(&wolf3d);
	init_camera(&wolf3d);
	raycasting(&wolf3d);
	return (0);
}
