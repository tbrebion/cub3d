/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 17:48:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int keysym);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, /*2620, 1080*/920, 600, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, /*2620, 1080*/920, 600);
	mlx_key_hook(g_data.win.ptr, &key_press, &g_data);
}

int	key_press(int keysym)
{
	if (keysym == 53)
	{
		// ft_putstr_fd("\nOKOKOKOK\n", 0);
		mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
		mlx_destroy_window(g_data.mlx.ptr, g_data.win.ptr);
		garcol_free_all();
		exit(0);
	}
	if (keysym == 119)
	{
		// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
		g_data.pos.y -= 10;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
		// printf("\nPOS_X :%f\n", g_data.pos.x);
	}
	if (keysym == 115)
	{
		g_data.pos.y += 10;
		// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
		// printf("\nPOS_X :%f\n", g_data.pos.x);
	}
	if (keysym == 100)
	{
		g_data.pos.x += 10;
		// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
		// printf("\nPOS_X :%f\n", g_data.pos.x);
	}
	if (keysym == 97)
	{
		g_data.pos.x -= 10;
		// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
		// printf("\nPOS_X :%f\n", g_data.pos.x);
	}
	return (1);
}
