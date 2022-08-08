/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/08 19:23:08 by tbrebion         ###   ########.fr       */
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

typedef struct	s_mlx
{
	void	*mlx_ptr;
}	t_mlx;

typedef struct	s_win
{
	void	*win_ptr;
	int		x;
	int		y;
}	t_win;

typedef struct	s_game
{
	int		max_len;
	char	**map;
	char	**file;
}	t_game;

typedef struct	s_data
{
	t_game	game;
	t_list	**garbage;
}	t_data;

extern t_data	g_data;

//////////////
// CHECKER x INIT
//////////////
void	check_and_init(int ac, char **av);
char	**save_file(char **av);
char	**save_map(char **file);
int		first_map_line(char **file);
int		checker_map(void);
int		first_line_map(char *str);
int		start_saving_map(int fd, char **av);
void	del_last_backslash_n(char *str);
char	*add_end_spaces(char *str);
char	*save_map_loop(char **save, char **file, int k, int i);

//////////////
// UTILS
//////////////
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **spl, int free_spl);

//////////////
// GARBAGE COLLECTOR
//////////////
void	garcol_add(void *var);
void	garcol_free_all(void);


#endif
