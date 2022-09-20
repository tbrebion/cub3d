/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:24:37 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/20 12:13:25 by flcarval         ###   ########.fr       */
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
	{
		printf("Error : Texture defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	del_last_backslash_n(str);
	g_data.utils.params.NO_path = str;
}

void	SO_handler(char *str)
{
	if (g_data.utils.params.SO_path)
	{
		printf("Error : Texture defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	del_last_backslash_n(str);
	g_data.utils.params.SO_path = str;
}

void	WE_handler(char *str)
{
	if (g_data.utils.params.WE_path)
	{
		printf("Error : Texture defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	del_last_backslash_n(str);
	g_data.utils.params.WE_path = str;
}

void	EA_handler(char *str)
{
	if (g_data.utils.params.EA_path)
	{
		printf("Error : Texture defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	del_last_backslash_n(str);
	g_data.utils.params.EA_path = str;
}

void	F_handler(char *str)
{
	char	**split;
	int		i;

	if (count_char(',', str) != 2)
	{
		printf("Error : Wrong color fomat in file.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	if (g_data.utils.params.colors_f[0] != -1)
	{
		printf("Error : F defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	split = garcol_split(str, ',');
	if (split_len(split) != 3)
	{
		printf("Error : Wrong color fomat in file.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			printf("Error in game parameters (colors)\n");
			garcol_free_all();
			exit(42);
		}
		g_data.utils.params.colors_f[i] = ft_atoi(split[i]);
		i++;
	}
}

void	C_handler(char *str)
{
	char	**split;
	int		i;

	if (count_char(',', str) != 2)
	{
		printf("Error : Wrong color fomat in file.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	if (g_data.utils.params.colors_c[0] != -1)
	{
		printf("Error : C defined multiple times.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	split = garcol_split(str, ',');
	if (split_len(split) != 3)
	{
		printf("Error : Wrong color fomat in file.\n");
		garcol_free_all();
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			printf("Error in game parameters (colors)\n");
			garcol_free_all();
			exit(42);
		}
		g_data.utils.params.colors_c[i] = ft_atoi(split[i]);
		i++;
	}
}
