/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/16 16:14:08 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, W, H, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, W, H);
	init_texture();
}

int	ft_key(int keysym)
{
	if (keysym == XK_Escape)
		ft_close();
	else if (keysym == XK_w) 
		ft_ws(1);
	else if (keysym == XK_s) 
		ft_ws(-1);
	else if (keysym == XK_d) 
		ft_ad(1);
	else if (keysym == XK_a) 
		ft_ad(-1);
	else if (keysym == XK_Left)
		ft_rotate(-1);
	else if (keysym == XK_Right)
		ft_rotate(1);
	screen_loop();
	draw();
	player_mini_map();
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
	g_data.pos.y += d * (g_data.dir.x * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.y -= d * (g_data.dir.x * SPEED / 100);
}

static void	ft_rotate(double d)
{
	double	dist;

	g_data.dir.x = g_data.dir.x * cos(d * TURN) - g_data.dir.y * sin(d * TURN);
	g_data.dir.y = g_data.dir.y * cos(d * TURN) + g_data.dir.x * sin(d * TURN);
	dist = hypot(g_data.dir.x, g_data.dir.y);
	g_data.dir.x /= dist;
	g_data.dir.y /= dist;
}
