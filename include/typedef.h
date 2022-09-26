/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/25 17:20:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "cub3d.h"

#define SIZE 8
#define SPEED 60
#define TURN 0.15
#define PI 3.141592653589793
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4
#define H 1080//1440
#define W 1920//2560
#define TEX_S 1024
// #define TEX_H 1024

typedef struct	s_mlx
{
	void	*ptr;
}	t_mlx;

typedef struct	s_win
{
	void	*ptr;
	// int		*w;
	// int		*h;
}	t_win;

typedef struct s_img
{
	void	*ptr;
	char	*adr;
	int		x;
	int		y;
	int		bpp;
	int		ll;
	int		end;
}	t_img;

typedef struct	s_map
{
	char	**tab;
	int		w;
	int		h;
}	t_map;

// typedef struct	s_tex
// {
// 	void	*n;
// 	void	*s;
// 	void	*e;
// 	void	*w;
// 	char	*n_adr;
// 	char	*s_adr;
// 	char	*e_adr;
// 	char	*w_adr;
// }	t_tex;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct	s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct	s_ray
{
	double	x;
	double	y;
	double	v;
	double	w;
	int		i;
}	t_ray;

typedef struct	s_hit
{
	double	x;
	double	y;
	double	d;
	int		side;
}	t_hit;

typedef struct	s_params
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		colors_f[3];
	int		colors_c[3];
}	t_params;

typedef struct	s_utils
{
	int			max_len;
	char		**file;
	t_params	params;
	double		line_height;
	double		step;
}	t_utils;

typedef struct	s_dist
{
	double	dist;
	int		side;
}	t_dist;

typedef struct s_wall
{
	double	top;
	double	bot;
	// int	count;
	// int	line_y;
	// int	y;
}	t_wall;

typedef struct	s_data
{
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_img		sprites[4];
	t_map		map;
	// t_tex		tex;
	t_pos		pos;
	t_dir		dir;
	t_ray		ray;
	t_hit		hit;
	t_dist		dist;
	t_utils		utils;
	t_wall		wall;
	t_list		**garbage;
}	t_data;

#endif