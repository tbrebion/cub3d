/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:21:33 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/20 12:20:30 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void	set_empty_params(void);
static int	detect_param(char *str);
static int	is_only_ones(char *str);
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
			param_handler(garcol_split(header[i], ' ')[1], detect_param(header[i]));
		else if (header[i][0] != '\n')
		{
			printf("Error : Unexpected field in file.\n");
			garcol_free_all();
			exit(EXIT_FAILURE);
		}
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
	{
		printf("ERROR : Missing a parametor.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
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
		header[j] = ft_strndup(g_data.utils.file[j], ft_strlen(g_data.utils.file[j]));
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
	else if (!ft_strcmp(line[0], "C"))
		return (6);
	else
		return (0);
}

static int	is_only_ones(char *str)
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

static void	param_handler(char *str, int param)
{
	if (param == 1)
		NO_handler(str);
	else if (param == 2)
		SO_handler(str);
	else if (param == 3)
		WE_handler(str);
	else if (param == 4)
		EA_handler(str);
	else if (param == 5)
		F_handler(str);
	else if (param == 6)
		C_handler(str);
}

static void	set_empty_params(void)
{
	g_data.utils.params.EA_path = NULL;
	g_data.utils.params.NO_path = NULL;
	g_data.utils.params.SO_path = NULL;
	g_data.utils.params.WE_path = NULL;
	g_data.utils.params.colors_c[0] = -1;
	g_data.utils.params.colors_f[0] = -1;
	g_data.utils.params.colors_c[1] = -1;
	g_data.utils.params.colors_f[1] = -1;
	g_data.utils.params.colors_c[2] = -1;
	g_data.utils.params.colors_f[2] = -1;
}
