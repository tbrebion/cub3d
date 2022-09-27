/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:27:39 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/27 14:19:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	no_handler(char *str)
{
	if (g_data.utils.params.no_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.no_path = str;
}

void	so_handler(char *str)
{
	if (g_data.utils.params.so_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.so_path = str;
}

void	we_handler(char *str)
{
	if (g_data.utils.params.we_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.we_path = str;
}

void	ea_handler(char *str)
{
	if (g_data.utils.params.ea_path)
		ft_error("Texture defined multiple times");
	del_last_backslash_n(str);
	g_data.utils.params.ea_path = str;
}
