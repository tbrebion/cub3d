/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:27:39 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/26 14:30:05 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	no_handler(char *str)
{
	if (g_data.utils.params.NO_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.NO_path = str;
}

void	so_handler(char *str)
{
	if (g_data.utils.params.SO_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.SO_path = str;
}

void	we_handler(char *str)
{
	if (g_data.utils.params.WE_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.WE_path = str;
}

void	ea_handler(char *str)
{
	if (g_data.utils.params.EA_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.EA_path = str;
}
