/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/26 17:35:21 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_arg(int ac, char **av);
static void	init_pos(void);
static void	get_dir(char c);

void	check_init_file(int ac, char **av)
{
	check_arg(ac, av);
	g_data.garbage = malloc(sizeof(t_list *));
	*g_data.garbage = NULL;
	g_data.utils.file = save_file(av);
	if (!g_data.utils.file)
		ft_error("Invalid file");
	g_data.utils.max_len = 0;
	g_data.map.tab = save_map(g_data.utils.file);
	if (!g_data.map.tab || checker_map())
		ft_error("Map error");
	get_game_params();
	init_pos();
}

static void	init_pos(void)
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
