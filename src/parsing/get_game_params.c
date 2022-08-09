/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:33 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/09 17:26:59 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	detect_param(char *str);

int	get_game_params()
{
	int	i;

	i = 0;

	return (0);
}

static int	detect_param(char *str)
{
	char	**line;

	line = garcol_split(str, ' ');
	if (!ft_strcmp(line[0], "NO"))
		return (1);
	else if (!ft_strcmp(line[0], "SO"))
		return (2);
	else if (!ft_strcmp(line[0], "WE"))
		return (3);
	else if (!ft_strcmp(line[0], "EA"))
		return (4);
	else if (!ft_strcmp(line[0], "F"))
		return (5);
	else
		return (0);
}

