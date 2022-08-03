/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 16:29:22 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
static void	print_map(char **map);
static void	print_file(char **file);

void	check_and_init(int ac, char **av)
{
	check_arg(ac, av);
	g_data.game.file = save_file(av);
	if (!g_data.game.file)
	{
		printf("INVALID FILE\n");
		exit(EXIT_FAILURE);
	}
	g_data.game.map = save_map(g_data.game.file);
	g_data.game.max_len = 0;
	if (!g_data.game.file || checker_map())
	{
		printf("MAP ERROR\n");
		free_split(g_data.game.map, 1);
		free_split(g_data.game.file, 1);
		exit(EXIT_FAILURE);
	}
	printf("\n\nFILE:\n\n");
	print_file(g_data.game.file);
	printf("\n\nMAP:\n\n");
	print_map(g_data.game.map);
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
