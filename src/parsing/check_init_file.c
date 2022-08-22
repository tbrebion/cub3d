/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 18:34:43 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
static void	print_map(char **map);
static void	print_file(char **file);
static void	print_params(t_game_params params);

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
	///////////////////////
	printf("\n\nFILE:\n\n");
	print_file(g_data.utils.file);
	printf("\n\nMAP:\n\n");
	print_map(g_data.map.tab);
	printf("\n\nPARAMS:\n\n");
	print_params(g_data.utils.params);
	//////////////////////////////
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

static void	print_params(t_game_params params)
{
	printf("NO_path = %s\n", params.NO_path);
	printf("SO_path = %s\n", params.SO_path);
	printf("WE_path = %s\n", params.WE_path);
	printf("EA_path = %s\n", params.EA_path);
	printf("colors = %d,%d,%d\n", params.colors[0], params.colors[1], params.colors[2]);
}
