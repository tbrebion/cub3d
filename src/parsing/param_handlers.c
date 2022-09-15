/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:24:37 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/15 15:35:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* ???
EST CE QUE ON AJOUTE UNE SECURITE AU MOMENT DU HANDLER POUR VERIFIER
LE PATH ET SON OUVERTURE
??? */

void	NO_handler(char *str)
{
	g_data.utils.params.NO_path = str;
}

void	SO_handler(char *str)
{
	g_data.utils.params.SO_path = str;
}

void	WE_handler(char *str)
{
	g_data.utils.params.WE_path = str;
}

void	EA_handler(char *str)
{
	g_data.utils.params.EA_path = str;
}

void	F_handler(char *str)
{
	char	**split;
	int		i;

	split = garcol_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(split[i]) < 0)
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

	split = garcol_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(split[i]) < 0)
		{
			printf("Error in game parameters (colors)\n");
			garcol_free_all();
			exit(42);
		}
		g_data.utils.params.colors_c[i] = ft_atoi(split[i]);
		i++;
	}
}
