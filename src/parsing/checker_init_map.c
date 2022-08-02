/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/02 19:44:14 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
static int	is_good_char(char c);
static int	check_char_map(void);
static	int	check_player(void);
static void	print_map(char **map);

void	check_and_init(int ac, char **av)
{
	check_arg(ac, av);
	g_data.game.map = save_map(av);
	g_data.game.max_len = 0;
	if (check_char_map() || checker_map() || check_player() != 1)
	{
		printf("Map Error\n");
		free_split(g_data.game.map, 1);
		exit(EXIT_FAILURE);
	}
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

static int	check_char_map(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(g_data.game.map[i])
	{
		while (g_data.game.map[i][j])
		{
			if (is_good_char(g_data.game.map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	is_good_char(char c)
{
	if (c != '0' && c != '1' \
		&& c != 'N' && c != 'S' \
		&& c != 'E' && c != 'W' \
		&& c != ' ')
		return (1);
	return (0);
}

static	int	check_player(void)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (g_data.game.map[i])
	{
		while (g_data.game.map[i][j])
		{
			if (g_data.game.map[i][j] == 'N' || g_data.game.map[i][j] == 'S' \
			|| g_data.game.map[i][j] == 'E' || g_data.game.map[i][j] == 'W')
				player++;
			j++;
		}
		j = 0;
		i++;
	}
	return (player);
}

static void	print_map(char **map)
{
	int	i;

	i = -1;
	printf("////////////////////////////\n");
	while(map[++i])
		printf("%s1\n", map[i]);
	printf("////////////////////////////\n");
}
