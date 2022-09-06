/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/06 16:04:04 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);
static void	ray_right(void);
// static void	ray_left(void);
static int which_side(void);
static void draw_right(int half_win);
// static void draw_left(int half_win);

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
	
	ray_right();
	// ray_left();
	// others_ray(-1);
	// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);

	printf("//////////////////////////////////////////\n");
	printf("RAYX %f    RAYY %f", g_data.ray.x, g_data.ray.y);
	printf("//////////////////////////////////////////\n");
	////////////////////////////////////////////////////////////
	printf("//////////////////////////////////////////\n");
	printf("\nPOSx : %f\n\nPOSy : %f\n\n", g_data.pos.x, g_data.pos.y);
	printf("//////////////////////////////////////////\n");
	printf("\nDIRx : %f\n\nDIRy : %f\n\n", g_data.dir.x, g_data.dir.y);
	printf("//////////////////////////////////////////\n");
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
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

static void	ray_right(void)
{
	double 	x;
	double 	y;
	double 	tmpx;
	double 	tmpy;
	int		j;
	double 	angle;
	int		side;

	int	half_win = g_data.win.x / 2;

	angle = 0.0;
	tmpx = 0.0;
	tmpy = 0.0;
	j = 0;
	while (angle < 0.5)
	{
		x = g_data.pos.x;
		y = g_data.pos.y;
		tmpx = g_data.dir.x * cos(1 * angle) - g_data.dir.y * sin(1 * angle);
		tmpy = g_data.dir.y * cos(1 * angle) + g_data.dir.x * sin(1 * angle);
		while (j < g_data.win.x * 2)
		{
			x += (tmpx * SPEED / 1000);
			y += (tmpy * SPEED / 1000);
			if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				break;
			}
			// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		}
		side = which_side();
		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
		draw_right(half_win);
		angle += 0.005;
		half_win--;
	}
}

// static void	ray_left(void)
// {
// 	double 	x;
// 	double 	y;
// 	double 	tmpx;
// 	double 	tmpy;
// 	int		j;
// 	double 	angle;
// 	int		side;

// 	angle = 0.0;
// 	tmpx = 0.0;
// 	tmpy = 0.0;
// 	j = 0;
// 	while (angle < 0.5)
// 	{
// 		x = g_data.pos.x;
// 		y = g_data.pos.y;
// 		tmpx = g_data.dir.x * cos(-1 * angle) - g_data.dir.y * sin(-1 * angle);
// 		tmpy = g_data.dir.y * cos(-1 * angle) + g_data.dir.x * sin(-1 * angle);
// 		while (j < g_data.win.x * 2)
// 		{
// 			x += (tmpx * SPEED / 1000);
// 			y += (tmpy * SPEED / 1000);
// 			if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
// 			{
// 				g_data.hit.x = x;
// 				g_data.hit.y = y;
// 				break;
// 			}
// 			mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
// 		}
// 		side = which_side();
// 		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
// 		draw_wall();
// 		angle += 0.005;
// 	}
// }

static int which_side(void)
{
	if ((g_data.hit.y - floor(g_data.hit.y)) == 0)
	{
		if (g_data.pos.y < g_data.hit.y)
			return (SOUTH);
		else 
			return (NORTH);
	}
	if ((g_data.hit.x - floor(g_data.hit.x)) == 0)
	{
		if (g_data.pos.x < g_data.hit.x)
			return (EAST);
		else 
			return (WEST);
	}
	return (-1);
}

static void draw_right(int half_win)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	// double x;
	// double y;
	// int half_win;
	int	i;

	// half_win = g_data.win.x / 2;
	i = 0;
	line_height = SIZE / g_data.dist.dist;
	draw_start = -line_height / 2 + SIZE / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SIZE / 2;
	if (draw_end >= SIZE)
		draw_end = SIZE - 1;
	// while (half_win > i)
	// {
	while (draw_start < draw_end)
	{
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, half_win, draw_start, 0X00FFFFFF);
		draw_start++;
	}
		// half_win--;
	// }
	
	// x = g_data.hit.x;
	// y = g_data.hit.y;
	
}
