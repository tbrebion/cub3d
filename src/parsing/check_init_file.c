/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/14 15:34:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
// static int	player_pos(char c);
static void	init_pos(void);
static void	get_dir(char c);

////////////////////
static void	print_map(char **map);
static void	print_file(char **file);
static void	print_params(t_params params);
////////////////////

void	check_init_file(int ac, char **av)
{
	check_arg(ac, av);
	g_data.garbage = malloc(sizeof(t_list *));
	*g_data.garbage = NULL;
	g_data.utils.file = save_file(av);
	if (!g_data.utils.file)
	{
		printf("INVALID FILE\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	g_data.utils.max_len = 0;
	g_data.map.tab = save_map(g_data.utils.file);
	if (!g_data.map.tab || checker_map())
	{
		printf("MAP ERROR\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	get_game_params();
	init_pos();
	///////////////////////
	printf("\n\nFILE:\n\n");
	print_file(g_data.utils.file);
	printf("\n\nMAP:\n\n");
	print_map(g_data.map.tab);
	printf("\n\nPARAMS:\n\n");
	print_params(g_data.utils.params);
	//////////////////////////////
}

static void init_pos(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_data.map.tab[i])
	{
		while (g_data.map.tab[i][j])
		{
			if (player_pos(g_data.map.tab[i][j]))
			{
				g_data.pos.x = j + 0.5;
				g_data.pos.y = i + 0.5;
				get_dir(g_data.map.tab[i][j]);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	
}

static void	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nwrong number of args !\n");
		exit(-1);
	}
	if (!ft_strrchr((char *)av[1], '.'))
	{
		printf("Error\ninvalid arg !\n");
		exit(-1);
	}
	if (ft_strcmp(ft_strrchr((char *)av[1], '.'), ".cub") != 0)
	{
		printf("Error\nfile must be \"<name>.cub\" !\n");
		exit(-1);
	}
}


int	player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	get_dir(char c)
{
	if (c == 'E' || c == 'W')
		g_data.dir.x = 1;
	else
		g_data.dir.x = 0;
	if (c == 'W')
		g_data.dir.x *= -1;
	else
		g_data.dir.x *= 1;
	if (c == 'N' || c == 'S')
		g_data.dir.y = 1;
	else
		g_data.dir.y = 0;
	if (c == 'N')
		g_data.dir.y *= -1;
	else
		g_data.dir.y *= 1;
}

static void	print_file(char **file)
{
	int	i;

	i = -1;
	printf("////////////////////////////////\
///////////////////////////////////////////////////\n");
	while (file[++i])
		printf("%s", file[i]);
	printf("\n////////////////////////////////\
///////////////////////////////////////////////////\n");
}

static void	print_map(char **map)
{
	int	i;

	i = -1;
	printf("////////////////////////////////\
///////////////////////////////////////////////////\n");
	while (map[++i])
		printf("%s1\n", map[i]);
	printf("////////////////////////////////\
///////////////////////////////////////////////////\n");
}

static void	print_params(t_params params)
{
	printf("NO_path = %s\n", params.NO_path);
	printf("SO_path = %s\n", params.SO_path);
	printf("WE_path = %s\n", params.WE_path);
	printf("EA_path = %s\n", params.EA_path);
	// printf("colors = %d,%d,%d\n", params.colors[0], params.colors[1], params.colors[2]);
}
