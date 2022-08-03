/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:55 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 10:04:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_proximity(int i, int j);

int	checker_map(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_data.game.map[i])
	{
		while (g_data.game.map[i][j])
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
	if (g_data.game.map[i][j] != '1' && g_data.game.map[i][j] != ' ')
	{
		if (!(g_data.game.map[i + 1][j]) || !(g_data.game.map[i][j + 1])
		|| !(g_data.game.map[i - 1][j]) || !(g_data.game.map[i][j - 1]))
			return (1);
		else if (g_data.game.map[i + 1][j] == ' ' || g_data.game.map[i][j + 1] == ' '
		|| g_data.game.map[i - 1][j] == ' ' || g_data.game.map[i][j - 1] == ' ')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	begin_map(void)	
{

}
