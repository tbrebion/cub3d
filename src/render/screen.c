/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:51:47 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/12 12:10:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray(void)
{
	double 	x;
	double 	y;
	double 	raydir_x;
	double 	raydir_y;
	int		j;
	double 	angle;
	int		side;

	angle = -0.5;
	raydir_x = g_data.dir.x * cos(-1 * 0.5) - g_data.dir.y * sin(-1 * 0.5);
	raydir_y = g_data.dir.y * cos(-1 * 0.5) + g_data.dir.x * sin(-1 * 0.5);
	j = 0;
	while (/*angle < 0.5*/j < W)
	{
		raydir_x = g_data.dir.x * cos(1 * angle) - g_data.dir.y * sin(1 * angle);
		raydir_y = g_data.dir.y * cos(1 * angle) + g_data.dir.x * sin(1 * angle);
		x = floor(g_data.pos.x) + g_data.dir.v;
		y = g_data.pos.y + (x - g_data.pos.x) * (raydir_y / raydir_x);
		while (/*j < g_data.win.x*/(int)floor(y) > 0 && (int)floor(y) < g_data.map.y)
		{
			if (g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.dir.v)] == '1')
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				break;
			}
			x += (2 * g_data.dir.v - 1);
			y += (2 * g_data.dir.v - 1) * g_data.dir.y / g_data.dir.x;
			mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		}
		side = which_side();
		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
		// draw_line(start_x, side, 1);
		angle += 0.0025;
		j++;
	}
}

void	ft_dir(void)
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



// void draw_line(int start_x, int side, int screen)
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