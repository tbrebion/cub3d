/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/29 13:07:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "cub3d.h"

#define SIZE 32 //16
#define SPEED 15
#define TURN 0.5
#define PI 3.141592653589793

typedef struct	s_mlx
{
	void	*ptr;
}	t_mlx;

typedef struct	s_win
{
	void	*ptr;
	int		x;
	int		y;
}	t_win;

typedef struct	s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_img
{
	void			*ptr;
	unsigned int	adr;
	int				fsh;
}	t_img;

typedef struct	s_map
{
	char	**tab;
	int		x;
	int		y;
	int		spr;
}	t_map;

typedef struct	s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*i;
	unsigned int	c;
	unsigned int	f;
}	t_tex;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct	s_dir
{
	double	x;
	double	y;
	double	a;
}	t_dir;

typedef struct	s_ray
{
	double	x;
	double	y;
	double	i;
	double	v;
	double	w;
}	t_ray;

typedef struct	s_hit
{
	double	x;
	double	y;
	double	d;
}	t_hit;

typedef struct	s_game_params
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		colors[3];
}	t_game_params;

typedef struct	s_utils
{
	int				max_len;
	char			**file;
	t_game_params	params;
}	t_utils;

typedef struct	s_data
{
	t_mlx	mlx;
	t_win	win;
	t_key	key;
	t_img	img;
	t_map	map;
	t_tex	tex;
	t_pos	pos;
	t_dir	dir;
	t_ray	ray;
	t_hit	hit;
	t_utils	utils;
	t_list	**garbage;
}	t_data;

#endif

// Linux qwerty :

// define ROTATE_LEFT 65361
// define ROTATE_RIGHT 65363
// define FORWARD_W 119
// define BACK_S 115
// define RIGHT_D 100
// define LEFT_A 97

// Linux azerty :

// define ROTATE_LEFT 65361
// define ROTATE_RIGHT 65363
// define FORWARD_Z 122
// define BACK_S 115
// define RIGHT_D 100
// define LEFT_Q 113
