/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:10 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/09 18:50:27 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init(void)
{
	g_data.mlx->mlx_ptr = mlx_init();
	g_data.win->x = 1920;
	g_data.win->y = 1080;
	g_data.win->win_ptr = mlx_new_window(g_data.mlx->mlx_ptr, g_data.win->x,\
		g_data.win->y, "./cub3d");
}