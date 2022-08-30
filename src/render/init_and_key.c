/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/30 17:39:53 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);
static void	ray_player(void);
static void	ray_30_right(void);
static void	ray_30_left(void);
// static void	ray(void);

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
	ray_player();
	ray_30_left();
	ray_30_right();
	// ray();
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);

	printf("//////////////////////////////////////////\n");
	printf("RAYX %f    RAYY %f", g_data.ray.x, g_data.ray.y);
	printf("//////////////////////////////////////////\n");
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

static void	ray_player(void)
{
	int		i;
	double	x;
	double	y;
	// double	hitx;
	// double	hity;

	i = 0;
	x = g_data.pos.x;
	y = g_data.pos.y;
	while (i < g_data.win.x * 2)
	{
		x += (g_data.dir.x * SPEED / 1000);
		y += (g_data.dir.y * SPEED / 1000);
		if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
		{
			// hitx = x;
			// hity = y;
			break ;
		}
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		i++;
	}
}
static void	ray_30_right(void)
{
	int		i;
	double	x;
	double	y;
	double	tmpdirx;
	double	tmpdiry;
	int		d;

	i = 0;
	d = 1;
	x = g_data.pos.x;
	y = g_data.pos.y;
	tmpdirx = g_data.dir.x * cos(d * 0.5) - g_data.dir.y * sin(d * 0.5);
	tmpdiry = g_data.dir.y * cos(d * 0.5) + g_data.dir.x * sin(d * 0.5);
	while (i < g_data.win.x * 2)
	{
		x += (tmpdirx * SPEED / 1000);
		y += (tmpdiry * SPEED / 1000);
		if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
		{
			break ;
		}
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		i++;
	}
}

static void	ray_30_left(void)
{
	int		i;
	double	x;
	double	y;
	double	tmpdirx;
	double	tmpdiry;
	int		d;

	i = 0;
	d = -1;
	x = g_data.pos.x;
	y = g_data.pos.y;
	tmpdirx = g_data.dir.x * cos(d * 0.5) - g_data.dir.y * sin(d * 0.5);
	tmpdiry = g_data.dir.y * cos(d * 0.5) + g_data.dir.x * sin(d * 0.5);
	while (i < g_data.win.x * 2)
	{
		x += (tmpdirx * SPEED / 1000);
		y += (tmpdiry * SPEED / 1000);
		if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
		{
			break ;
		}
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		i++;
	}
}

// static void	ray(void)
// {
// 	int	i;
// 	int	d;
// 	int	x;
// 	int	y;
// 	double	tmpdirx;
// 	double	tmpdiry;

// 	x = g_data.pos.x;
// 	y = g_data.pos.y;
// 	i = 0;
// 	d = 1;
// 	tmpdirx = g_data.dir.x * cos(d * 0.75) - g_data.dir.y * sin(d * 0.75);
// 	tmpdiry = g_data.dir.y * cos(d * 0.75) + g_data.dir.x * sin(d * 0.75);
// 	d = -1;
// 	while(tmpdirx != g_data.dir.x)
// 	{
// 		tmpdirx = g_data.dir.x * cos(d * 0.75) - g_data.dir.y * sin(d * 0.75);
// 		tmpdiry = g_data.dir.y * cos(d * 0.75) + g_data.dir.x * sin(d * 0.75);
// 		while (i < g_data.win.x * 2)
// 		{
// 			x += (tmpdirx * SPEED / 1000);
// 			y += (tmpdiry * SPEED / 1000);
// 			if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1')
// 			{
// 				break ;
// 			}
// 			mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
// 			i++;
// 		}
// 	}
// }

// static void	ray(void)
// {
// 	double	angle;
// 	double	dist;

// 	if (g_data.ray.i < g_data.win.x)
// 	{
// 		angle = ((g_data.ray.i - (g_data.win.x / 2)) * 33 / (g_data.win.x / 2));
// 		angle = ft_deg_to_rad(angle);
// 		g_data.ray.x = g_data.dir.x * cos(angle) - g_data.dir.y * sin(angle);
// 		g_data.ray.y = g_data.dir.y * cos(angle) + g_data.dir.x * sin(angle);
// 		dist = hypot(g_data.ray.x, g_data.ray.y);
// 		g_data.ray.x /= dist;
// 		g_data.ray.y /= dist;
// 		g_data.ray.i++;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);
// 	}
// }
