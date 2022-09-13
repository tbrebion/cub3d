/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:51:47 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/13 14:32:43 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_ver(void)
{
	double 	x;
	double 	y;

	x = floor(g_data.pos.x) + g_data.ray.v;
	y = g_data.pos.y + (x - g_data.pos.x) * (g_data.ray.y / g_data.ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < 1000)
	{
		if ((int)floor(y) > g_data.map.h || (int)(x - 1 + g_data.ray.v) > g_data.map.w)
			break;
		if (g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.ray.v)] == '1' || g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.ray.v)] == ' ')
		{
			g_data.hit.x = x;
			g_data.hit.y = y;
			g_data.hit.d = hypot(x - g_data.pos.x, y - g_data.pos.y);
			g_data.hit.side = which_side();
			return ;
		}
		x += (2 * g_data.ray.v - 1);
		y += (2 * g_data.ray.v - 1) * g_data.ray.y / g_data.ray.x;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
	}
	g_data.hit.x = g_data.pos.x;
	g_data.hit.y = g_data.pos.y;
	g_data.hit.d = 10000000;
	g_data.hit.side = 0;
	// g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
	// draw_line(start_x, side, 1);
}

void	ray_hor(void)
{
	double	x;
	double	y;

	y = floor(g_data.pos.y) + g_data.ray.w;
	x = g_data.pos.x + (y - g_data.pos.y) * (g_data.ray.x / g_data.ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < 1000)
	{
		if ((int)(y - 1 + g_data.ray.w) > g_data.map.h || (int)floor(x) > g_data.map.w)
			break;
		if (g_data.map.tab[(int)(y - 1 + g_data.ray.w)][(int)floor(x)] == '1' || g_data.map.tab[(int)(y - 1 + g_data.ray.w)][(int)floor(x)] == ' ')
		{
			if (g_data.hit.d > hypot(x - g_data.pos.x, y - g_data.pos.y))
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				g_data.hit.d = hypot(x - g_data.pos.x, y - g_data.pos.y);
				g_data.hit.side = which_side();
			}
			return ;
		}
		y += (2 * g_data.ray.w - 1);
		x += (2 * g_data.ray.w - 1) * g_data.ray.x / g_data.ray.y;
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
	}
}

void	ft_dir(void)
{
	if (g_data.ray.x >= 0)
		g_data.ray.v = 1;
	else
		g_data.ray.v = 0;
	if (g_data.ray.y >= 0)
		g_data.ray.w = 1;
	else
		g_data.ray.w = 0;
}

int which_side(void)
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

void	ray_rotate(void)
{
	double	angle;
	double	dist;

	angle = ((double)g_data.ray.i - (W / 2)) * 33 / (W / 2);
	angle = ft_deg_to_rad(angle);
	g_data.ray.x = g_data.dir.x * cos(angle) - g_data.dir.y * sin(angle);
	g_data.ray.y = g_data.dir.y * cos(angle) + g_data.dir.x * sin(angle);
	dist = hypot(g_data.ray.x, g_data.ray.y);
	g_data.ray.x /= dist;
	g_data.ray.y /= dist;
}

void	screen_loop(void)
{
	while (g_data.ray.i < W)
	{
		ray_rotate();
		ft_dir();
		ray_ver();
		ray_hor();
		// draw_line(g_data.ray.i, 1, 1);
		g_data.ray.i++;
	}
	g_data.ray.i = 0;
}

void draw_line(int start_x, int side, int screen)
{
	int	line_height;
	int	y;
	int	i;

	i = 0;
	while (i <= SIZE)
	{
		line_height = (H / g_data.dist.dist) * SIZE;
		y = H / 2;
		while (y - H / 2 < line_height / 2)
		{
			if (side < EAST /*&& side != 0*/)
				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2cc1cc);
			else
				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2c71cc);
			y++;
		}
		y = H / 2;
		while (abs(y - H / 2) < line_height / 2)
		{
			if (side < EAST /*&& side != 0*/)
				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2cc1cc);
			else
				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, start_x , y , 0X2c71cc);
			y--;
		}
		start_x += screen;
		i++;
	}
}