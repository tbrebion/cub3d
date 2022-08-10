/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/10 15:29:34 by tbrebion         ###   ########.fr       */
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
	int				max_len;
	char			**map;
	char			**file;
	t_game_params	params;
}	t_game;

typedef struct	s_data
{
	t_game	game;
	t_list	**garbage;
}	t_data;

#endif

