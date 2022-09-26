/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:33 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/26 17:39:59 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**get_header(void);
static void	param_handler(char *str, int param);

int	get_game_params(void)
{
	char	**header;
	int		i;

	set_empty_params();
	header = get_header();
	i = 0;
	while (header[i])
	{
		if (detect_param(header[i]))
			param_handler(garcol_split(header[i], ' ')[1], \
			detect_param(header[i]));
		else if (header[i][0] != '\n')
			ft_error("Unexpected field in file");
		i++;
	}
	if (!g_data.utils.params.EA_path || !g_data.utils.params.NO_path \
		|| !g_data.utils.params.SO_path || !g_data.utils.params.WE_path \
		|| g_data.utils.params.colors_c[0] == -1 \
		|| g_data.utils.params.colors_f[0] == -1 \
		|| g_data.utils.params.colors_c[1] == -1 \
		|| g_data.utils.params.colors_f[1] == -1 \
		|| g_data.utils.params.colors_c[2] == -1 \
		|| g_data.utils.params.colors_f[2] == -1)
		ft_error("Missing a paramettor");
	return (0);
}

static char	**get_header(void)
{
	int		i;
	int		j;
	char	**header;

	i = 0;
	while (!is_only_ones(g_data.utils.file[i]))
		i++;
	header = malloc(sizeof(char *) * (i + 1));
	if (!header)
		return (NULL);
	garcol_add(header);
	j = 0;
	while (j < i)
	{
		header[j] = ft_strndup(g_data.utils.file[j], \
		ft_strlen(g_data.utils.file[j]));
		garcol_add(header[j]);
		j++;
	}
	header[j] = NULL;
	return (header);
}

static void	param_handler(char *str, int param)
{
	if (param == 1)
		no_handler(str);
	else if (param == 2)
		so_handler(str);
	else if (param == 3)
		we_handler(str);
	else if (param == 4)
		ea_handler(str);
	else if (param == 5)
		f_handler(str);
	else if (param == 6)
		c_handler(str);
}
