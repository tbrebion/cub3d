/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/16 14:49:57 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "cub3d.h"

// typedef struct	s_mlx
// {
// 	void	*mlx_ptr;
// }	t_mlx;

// typedef struct	s_win
// {
// 	void	*win_ptr;
// 	int		x;
// 	int		y;
// }	t_win;

typedef struct	s_game_params
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		colors[3];
}	t_game_params;

typedef struct	s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	int				max_len;
	char			**map;
	char			**file;
	t_game_params	params;
}	t_game;

////////////////////////
typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
}					t_ray;
////////////////////////

typedef struct	s_data
{
	t_game	game;
	t_ray	ray;
	t_list	**garbage;
}	t_data;

#endif

