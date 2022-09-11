/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/11 23:06:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);
static void	ray_right(void);
static void	ray_left(void);
static int which_side(void);
// static void draw_line(int start_x, int side, int screen);
// static double	step(double raydir_x, double raydir_y);
static void	ft_dir(void);
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
	ft_dir();
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
	g_data.map.x = (int)floor(g_data.pos.x);
	g_data.map.y = (int)floor(g_data.pos.y);
	ft_dir();
	// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	ray_right();
	ray_left();
	// others_ray(-1);
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);

	// printf("//////////////////////////////////////////\n");
	// printf("RAYX %f    RAYY %f", g_data.ray.x, g_data.ray.y);
	// printf("//////////////////////////////////////////\n");
	// ////////////////////////////////////////////////////////////
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
	double 	raydir_x;
	double 	raydir_y;
	int		j;
	double 	angle;
	int		side;

	int	start_x = W / 2;

	angle = 0.0;
	raydir_x = 0.0;
	raydir_y = 0.0;
	j = 0;
	while (angle < 0.5)
	{
		raydir_x = g_data.dir.x * cos(1 * angle) - g_data.dir.y * sin(1 * angle);
		raydir_y = g_data.dir.y * cos(1 * angle) + g_data.dir.x * sin(1 * angle);
		x = floor(g_data.pos.x) + g_data.dir.v;//g_data.pos.x;
		y = g_data.pos.y + (x - g_data.pos.x) * (raydir_y / raydir_x); //g_data.pos.y;
		printf("//////////////////\nx %d\n  y %d\n////////////////\n", (int)(x - 1 + g_data.dir.v), (int)floor(y));
		printf("MAP[x][y] : [%c]\n", g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.dir.v)/*floor(x)*/]);
		while (j < g_data.win.x * 2)
		{
			if (g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.dir.v)/*floor(x)*/] == '1')
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				break;
			}
			x += (2 * g_data.dir.v - 1);//(raydir_x * step(raydir_x, raydir_y));
			y += (2 * g_data.dir.v - 1) * g_data.dir.y / g_data.dir.x;//(raydir_y * step(raydir_x, raydir_y));
			mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		}
		side = which_side();
		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
		// draw_line(start_x, side, 1);
		start_x += SIZE;
		angle += 0.0025;
	}
}

static void	ray_left(void)
{
	double 	x;
	double 	y;
	double 	raydir_x;
	double 	raydir_y;
	int		j;
	double 	angle;
	int		side;

	int	start_x = W / 2;

	angle = 0.0;
	raydir_x = 0.0;
	raydir_y = 0.0;
	j = 0;
	while (angle < 0.5)
	{
		// x = g_data.pos.x;
		// y = g_data.pos.y;
		raydir_x = g_data.dir.x * cos(-1 * angle) - g_data.dir.y * sin(-1 * angle);
		raydir_y = g_data.dir.y * cos(-1 * angle) + g_data.dir.x * sin(-1 * angle);
		x = floor(g_data.pos.x) + g_data.dir.v;//g_data.pos.x;
		y = g_data.pos.y + (x - g_data.pos.x) * (raydir_y / raydir_x); //g_data.pos.y;
		while (j < g_data.win.x * 2)
		{
			if (g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.dir.v)/*floor(x)*/] == '1')
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				break;
			}
			x += (2 * g_data.dir.v - 1);//(raydir_x * step(raydir_x, raydir_y));
			y += (2 * g_data.dir.v - 1) * g_data.dir.y / g_data.dir.x;//(raydir_y * step(raydir_x, raydir_y));
			// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		}
		side = which_side();
		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
		// draw_line(start_x, side, -1);
		start_x -= SIZE;
		angle += 0.0025;
	}
}

// static double	step(double raydir_x, double raydir_y)
// {
// 	// double	x;
// 	// double	y;
// 	double	x1;
// 	double	y1;
// 	double	x2;
// 	double	y2;
// 	double	diff_x;
// 	double	diff_y;
// 	double	step;
// 	// int		i;

// 	x1 = g_data.pos.x;
// 	y1 = g_data.pos.y;
// 	x1 -= raydir_x * SPEED / 100;
// 	y1 -= raydir_y * SPEED / 100;
// 	x2 = g_data.pos.x;
// 	y2 = g_data.pos.y;
// 	diff_x = x2 - x1;
// 	diff_y = y2 - y1;
// 	if (fabs(diff_x) >= fabs(diff_y))
// 		step = fabs(diff_x);
// 	else
// 		step = fabs(diff_y);
// 	// diff_x = diff_x / step;
// 	// diff_y = diff_y / step;
// 	// x = x1;
// 	// y = y1;
// 	// i = 1;
// 	// while (i <= step)
// 	// {
// 	// 	x += diff_x;
// 	// 	y += diff_y;
// 	// 	i++;
// 	// }
// 	return (step);
// }

static void	ft_dir(void)
{
	if (g_data.dir.x >= 0)
		g_data.dir.v = 1;
	else
		g_data.dir.v = 0;
	if (g_data.dir.y >= 0)
		g_data.dir.w = 1;
	else
		g_data.dir.w = 0;
}
static int which_side(void)
{
	static int	tmp_side = 0;

	if (fabs((int)round(g_data.hit.y) - g_data.hit.y) < fabs((int)round(g_data.hit.x) - g_data.hit.x))
	{
		if (g_data.pos.y > g_data.hit.y)
			tmp_side = NORTH;
		if (g_data.pos.y < g_data.hit.y)
			tmp_side = SOUTH;
	}
	else if (fabs((int)round(g_data.hit.y) - g_data.hit.y) > fabs((int)round(g_data.hit.x) - g_data.hit.x))
	{
		if (g_data.pos.x > g_data.hit.x)
			tmp_side = WEST;
		if (g_data.pos.x < g_data.hit.x)
			tmp_side = EAST;
	}
	return (tmp_side);
}

// static void draw_line(int start_x, int side, int screen)
// {
// 	int	line_height;
// 	int	y;
// 	int	i;

// 	i = 0;
// 	while (i <= SIZE)
// 	{
// 		line_height = (H / g_data.dist.dist) * SIZE;
// 		y = H / 2;
// 		while (y - H / 2 < line_height / 2)
// 		{
// 			if (side < EAST /*&& side != 0*/)
// 				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2cc1cc);
// 			else
// 				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2c71cc);
// 			y++;
// 		}
// 		y = H / 2;
// 		while (abs(y - H / 2) < line_height / 2)
// 		{
// 			if (side < EAST /*&& side != 0*/)
// 				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2cc1cc);
// 			else
// 				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2c71cc);
// 			y--;
// 		}
// 		start_x += screen;
// 		i++;
// 	}
// }