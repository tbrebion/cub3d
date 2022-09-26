/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:24:37 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/20 16:21:43 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* ???
EST CE QUE ON AJOUTE UNE SECURITE AU MOMENT DU HANDLER POUR VERIFIER
LE PATH ET SON OUVERTURE
??? */

void	NO_handler(char *str)
{
	if (g_data.utils.params.NO_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.NO_path = str;
}

void	SO_handler(char *str)
{
	if (g_data.utils.params.SO_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.SO_path = str;
}

void	WE_handler(char *str)
{
	if (g_data.utils.params.WE_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.WE_path = str;
}

void	EA_handler(char *str)
{
	if (g_data.utils.params.EA_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.EA_path = str;
}

void	F_handler(char *str)
{
	char	**split;
	int		i;

	if (count_char(',', str) != 2)
		ft_error("Wrong color fomat in file");
	if (g_data.utils.params.colors_f[0] != -1)
		ft_error("F defined multiple times");
	split = garcol_split(str, ',');
	if (split_len(split) != 3)
		ft_error("Wrong color fomat in file");
	i = 0;
	while (i < 3)
	{
		printf("color value #%d = %d\n", i, ft_atoi(split[i]));
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			ft_error("Error in game parameters (colors value)");
		g_data.utils.params.colors_f[i] = ft_atoi(split[i]);
		i++;
	}
}

void	C_handler(char *str)
{
	char	**split;
	int		i;

	if (count_char(',', str) != 2)
		ft_error("Wrong color fomat in file");
	if (g_data.utils.params.colors_c[0] != -1)
		ft_error("C defined multiple times");
	split = garcol_split(str, ',');
	if (split_len(split) != 3)
		ft_error("Wrong color fomat in file");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			ft_error("Error in game parameters (colors)");
		g_data.utils.params.colors_c[i] = ft_atoi(split[i]);
		i++;
	}
}
