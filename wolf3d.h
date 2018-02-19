/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 13:48:41 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/21 13:53:35 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define X (int)x
# define Y (int)y
# define ANGLE ((t_wolf *)param)->angle
# define CAMY ((t_wolf *)param)->poscamy
# define CAMX ((t_wolf *)param)->poscamx
# include "stdlib.h"
# include <math.h>
# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include "X.h"

typedef struct	s_tex
{
	int hori_x;
	int hori_y;
	int verti_x;
	int verti_y;

}				t_tex;

typedef struct	s_wolf
{
	char	height;
	int		angle;
	int		visual;
	double	poscamx;
	double	poscamy;
	double	raycast;
	int		projector_length;
	int		projector_height;
	int		dist_projector;
	int		offsethori;
	int		offsetverti;
	int		trueoffset;
	void	*win;
	void	*mlx;
	void	*image;
	void	*image_wall;
	char	*data_secret;
	void	*image_secret;
	void	*image_main;
	char	*data_main;
	char	*data_wall;
	char	*data;
	int		byte;
	int		line;
	int		endian;
	t_tex	change;

}				t_wolf;

int				red_cross(int key, t_wolf *wolf3d);
double			dda_hori(t_wolf *wolf3d, int map[12][21], double raycast);
double			dda_verti(t_wolf *wolf3d, int map[12][21], double raycast);
void			hori_or_verti(double hori, double verti, int *com);
void			hori_init(t_wolf *wolf3d,\
		double raycast, double hori, double *distcorrect);
void			verti_init(t_wolf *wolf3d,\
		double raycast, double verti, double *distcorrect);
void			color_main(t_wolf *wolf3d, int com, int map[12][21]);
void			draw(t_wolf *wolf3d, double distcorrect, int col);
double			ft_correct(t_wolf *wolf3d, double fish, double raycast);
void			incr(double *x, double *y, double *xa, double *ya);
int				key(int keycode, void *param);
void			color_wall_1(t_wolf *wolf3d, int map[12][21]);
void			boucle_ray(t_wolf *wolf3d, double raycast,\
		int map[12][21], double decal);
void			init_camera(t_wolf *wolf3d);
void			init_wolf(t_wolf *wolf3d);
void			raycasting(t_wolf *wolf3d);

#endif
