/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_params_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:37:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/27 14:19:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	detect_param(char *str)
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
	else if (!ft_strcmp(line[0], "C"))
		return (6);
	else
		return (0);
}

int	is_only_ones(char *str)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == '1')
			p = 1;
		if (!(str[i] == '1' || str[i] == ' ' || str[i] == '\n'))
			return (0);
		i++;
	}
	if (!p)
		return (0);
	return (1);
}

void	set_empty_params(void)
{
	g_data.utils.params.ea_path = NULL;
	g_data.utils.params.no_path = NULL;
	g_data.utils.params.so_path = NULL;
	g_data.utils.params.we_path = NULL;
	g_data.utils.params.colors_c[0] = -1;
	g_data.utils.params.colors_f[0] = -1;
	g_data.utils.params.colors_c[1] = -1;
	g_data.utils.params.colors_f[1] = -1;
	g_data.utils.params.colors_c[2] = -1;
	g_data.utils.params.colors_f[2] = -1;
}
