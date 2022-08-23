/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/23 13:53:48 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int keysym);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, 2620, 1080/*920, 600*/, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, 2620, 1080/*920, 600*/);
	// mlx_key_hook(g_data.win.ptr, &ft_key, &g_data);
}

int	ft_key(int keysym)
{
	if (keysym == XK_Escape)
		ft_close();
	if (keysym == XK_w)
	{
		g_data.pos.y -= 10;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
	}
	if (keysym == XK_s)
	{
		g_data.pos.y += 10;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
	}
	if (keysym == XK_d)
	{
		g_data.pos.x += 10;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
	}
	if (keysym == XK_a)
	{
		g_data.pos.x -= 10;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
	}
	// if (keysym == XK_Right)
	// {

	// }
	// if (keysym == XK_Left)
	// {

	// }
	return (1);
}

// int	key_pressed	
