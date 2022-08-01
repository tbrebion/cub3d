/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 15:16:15 by tbrebion         ###   ########.fr       */
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
	char	*l_map;
	char	**map;
}	t_game;

//////////////
// CHECKER x INIT 
//////////////
void	check_and_init(int ac, char **av, t_game *game);
void	check_arg(int ac, char **av);
char	*line_map(char **av);
char	**save_map(char *save);

//////////////
// UTILS
//////////////
int	ft_strcmp(const char *s1, const char *s2);

void	print_map(char **map);

#endif
