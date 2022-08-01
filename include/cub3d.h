/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 18:45:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../Lib42/include/lib42.h"

typedef struct	s_game
{
	char	**map;
}	t_game;

typedef struct	s_garbage
{
	void	*content;
	void	*next;
}	t_garbage;

extern t_data	g_data;

//////////////
// CHECKER x INIT 
//////////////
void	check_and_init(int ac, char **av, t_game *game);
char	**save_map(char **av);


//////////////
// UTILS
//////////////
int	ft_strcmp(const char *s1, const char *s2);
void	free_split(char **spl);

#endif
