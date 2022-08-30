/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/30 13:08:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);
static void	ray(void);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, g_data.win.x, g_data.win.y, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, g_data.win.x, g_data.win.y);
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
	ray();
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);

	// printf("//////////////////////////////////////////\n");
	// printf("RAYX %f    RAYY %f", g_data.ray.x, g_data.ray.y);
	// printf("//////////////////////////////////////////\n");
	////////////////////////////////////////////////////////////
	printf("//////////////////////////////////////////\n");
	printf("\nPOSx : %f\n\nPOSy : %f\n\n", g_data.pos.x, g_data.pos.y);
	printf("//////////////////////////////////////////\n");
	printf("\nDIRx : %f\n\nDIRy : %f\n\n", g_data.dir.x, g_data.dir.y);
	printf("//////////////////////////////////////////\n");
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
	////////////////////////////////////////////////////////////
	
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

static void	ray(void)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = g_data.pos.x;
	y = g_data.pos.y;
	while (/*g_data.map.tab[(int)floor(y)][(int)floor(x)] != '1'*/i < 5)
	{
		x += (g_data.dir.x * SPEED / 100);
		y += (g_data.dir.y * SPEED / 100);
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		i++;
	}
	// double	angle;
	// double	dist;

	// while (g_data.ray.i < g_data.win.x)
	// {
	// 	angle = ((g_data.ray.i - (g_data.win.x / 2)) * 33 / (g_data.win.x / 2));
	// 	angle = ft_deg_to_rad(angle);
	// 	g_data.ray.x = g_data.dir.x * cos(angle) - g_data.dir.y * sin(angle);
	// 	g_data.ray.y = g_data.dir.y * cos(angle) + g_data.dir.x * sin(angle);
	// 	dist = hypot(g_data.ray.x, g_data.ray.y);
	// 	g_data.ray.x /= dist;
	// 	g_data.ray.y /= dist;
	// 	g_data.ray.i++;
	// 	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);
	// }
}