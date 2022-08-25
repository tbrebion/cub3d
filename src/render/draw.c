/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:27:15 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/25 16:06:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_help(int x, int y);
static void	draw_help_dos(int x, int y);

void	draw(void)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (g_data.map.tab[i])
	{
		while (g_data.map.tab[i][j])
		{
			if (g_data.map.tab[i][j] == '1')
				draw_help(x, y);
			if (g_data.map.tab[i][j] == '0' || player_pos(g_data.map.tab[i][j]))
				draw_help_dos(x, y);
			x += SIZE;
			j++;	
		}
		x = 0;
		y += SIZE;
		j = 0;
		i++;
	}
	
}

static void	draw_help(int x, int y)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < (tmpy + SIZE))
	{
		while (x < (tmpx + SIZE))
		{
			mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x, y, 0x00FF0000);
			x++;
		}
		x = tmpx;
		y++;
	}
}

static void	draw_help_dos(int x, int y)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	while (y < (tmpy + SIZE)) //check hit ray
	{
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x, y, 0x00FF0000);
		y++;
	}
	y = tmpy;
	while (x < (tmpx + SIZE))
	{
		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x, y, 0x00FF0000);
		x++;
	}
}
// void	draw(void)
// {
// 	g_data.ray.x = 0;
// 	g_data.ray.y = 0;
// 	g_data.ray.i = 0;
// 	g_data.ray.v = 0;
// 	g_data.ray.w = 0;
// 	g_data.hit.x = 0;
// 	g_data.hit.y = 0;
// 	g_data.hit.d = 0;
	
// }
