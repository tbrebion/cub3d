/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:33 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/09 17:57:38 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	detect_param(char *str);
static int	is_only_ones(char *str);
static char	**get_header(void);

int	get_game_params()
{
	char	**header;

	header = get_header();
	
	return (0);
}

static char	**get_header(void)
{
	int		i;
	int		j;
	char	**header;

	i = 0;
	while (/*pas que des '1'*/ !is_only_ones(g_data.game.file[i]))
		i++;
	header = malloc(sizeof(char *) * i);
	if (!header)
		return (NULL);
	garcol_add(header);
	j = 0;
	while (j < i)
	{
		header[j] = ft_strdup(g_data.game.file[j]);
		garcol_add(header[j]);
		j++;
	}
	header[j] = NULL;
	return (header);
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

static int	is_only_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == ' ' || str[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

