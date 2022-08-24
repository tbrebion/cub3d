/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/24 17:18:14 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int	key_press(int keysym);
static void	ft_ws(double d);
static void	ft_ad(double d);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, 2558, 1080/*920, 600*/, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, 2558, 1080/*920, 600*/);
}

int	ft_key(int keysym)
{
	if (keysym == XK_Escape)
		ft_close();
	if (keysym == XK_w) 
		ft_ws(1);
	if (keysym == XK_s) 
		ft_ws(-1);
	if (keysym == XK_d) 
		ft_ad(1);
	if (keysym == XK_a) 
		ft_ad(-1);
	printf("//////////////////////////////////////////\n");
	printf("\nPOSx : %f\n\nPOSy : %f\n\n", g_data.pos.x, g_data.pos.y);
	printf("//////////////////////////////////////////\n");
	// if (keysym == XK_Right || keysym == XK_Left)
	// {
	// 	right_left__key(keysym);
	// }
	return (1);
}

static void	ft_ws(double d)
{
	g_data.pos.x += d * (g_data.dir.x * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.x -= d * (g_data.dir.x * SPEED / 100);
	g_data.pos.y += d * (g_data.dir.y * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.y -= d * (g_data.dir.y * SPEED / 100);
}

static void	ft_ad(double d)
{
	g_data.pos.x -= d * (g_data.dir.y * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.x += d * (g_data.dir.y * SPEED / 100);
	g_data.pos.y -= d * (g_data.dir.x * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.y += d * (g_data.dir.x * SPEED / 100);
}

// void	right_left__key(int keysym)
// {
// 	if (keysym == XK_Right)
// 	{

// 	}
// 	if (keysym == XK_Left)
// 	{

// 	}
// }
// // int	key_pressed	


//////////////////////////////////////////////////////


// void	wasd_key(int keysym)
// {
// 	if (keysym == XK_w)
// 	{
// 		g_data.pos.y -= 0.75;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
// 	}
// 	if (keysym == XK_s)
// 	{
// 		g_data.pos.y += 0.75;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
// 	}
// 	if (keysym == XK_d)
// 	{
// 		g_data.pos.x += 0.75;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
// 	}
// 	if (keysym == XK_a)
// 	{
// 		g_data.pos.x -= 0.75;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
// 	}
// }

