/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 18:33:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
static void	init_map(t_game *game, char **av);
// static int	check_char_map(t_game *game);
static void	print_map(char **map);

void	check_and_init(int ac, char **av, t_game *game)
{
	check_arg(ac, av);
	init_map(game, av);
	print_map(game->map);
	
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

static void	init_map(t_game *game, char **av)
{
	game->map = save_map(av);
}

// static int	check_char_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while(game->l_map[i])
// 	{
// 		if (game->l_map[i] != '0' && game->l_map[i] != '1' \
// 		&& game->l_map[i] != 'N' && game->l_map[i] != 'S' \
// 		&& game->l_map[i] != 'E' && game->l_map[i] != 'W' && game->l_map[i] != ' ')
// 		{
// 			printf("Map Error\n");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static void	print_map(char **map)
{
	int	i;

	i = -1;
	while(map[++i])
		printf("%s", map[i]);
}