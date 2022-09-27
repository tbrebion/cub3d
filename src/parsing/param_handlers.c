/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:24:37 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/27 14:13:33 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	f_handler(char *str)
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
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			ft_error("Error in game parameters (colors value)");
		g_data.utils.params.colors_f[i] = ft_atoi(split[i]);
		i++;
	}
}

void	c_handler(char *str)
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
