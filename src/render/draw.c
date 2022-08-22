/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:27:15 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 17:26:53 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw(int x, int y);

void	draw_map(void)
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
				draw(x, y);
			x += SIZE;
			j++;	
		}
		x = 0;
		y += SIZE;
		j = 0;
		i++;
	}
	
}

static void	draw(int x, int y)
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
