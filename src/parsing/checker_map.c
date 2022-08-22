/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:55 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 17:09:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_good_char(char c);
static int	check_char_map(void);
static int	check_player(void);
static int	check_proximity(int i, int j);

int	checker_map(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_char_map() || check_player() != 1)
		return (1);
	while (g_data.map.tab[i])
	{
		while (g_data.map.tab[i][j])
		{
			if (check_proximity(i, j))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	check_proximity(int i, int j)
{
	if (g_data.map.tab[i][j] != '1' && g_data.map.tab[i][j] != ' ')
	{
		if (!(g_data.map.tab[i + 1][j]) || !(g_data.map.tab[i][j + 1])
		|| !(g_data.map.tab[i - 1][j]) || !(g_data.map.tab[i][j - 1]))
			return (1);
		if (g_data.map.tab[i + 1][j] == ' ' || g_data.map.tab[i][j + 1] == ' '
		|| g_data.map.tab[i - 1][j] == ' ' || g_data.map.tab[i][j - 1] == ' ')
			return (1);
		else
			return (0);
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

static int	check_char_map(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_data.map.tab[i])
	{
		while (g_data.map.tab[i][j])
		{
			if (is_good_char(g_data.map.tab[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	check_player(void)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (g_data.map.tab[i])
	{
		while (g_data.map.tab[i][j])
		{
			if (g_data.map.tab[i][j] == 'N' || g_data.map.tab[i][j] == 'S' \
			|| g_data.map.tab[i][j] == 'E' || g_data.map.tab[i][j] == 'W')
				player++;
			j++;
		}
		j = 0;
		i++;
	}
	return (player);
}
