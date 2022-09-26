/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:39:17 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/26 14:40:41 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	jump_line_tex(int step)
{
	if (g_data.hit.side == NORTH)
		g_data.sprites[0].adr += 1024 * (g_data.sprites[0].bpp / 8) * step;
	if (g_data.hit.side == SOUTH)
		g_data.sprites[1].adr += 1024 * (g_data.sprites[1].bpp / 8) * step;
	if (g_data.hit.side == EAST)
		g_data.sprites[2].adr += 1024 * (g_data.sprites[2].bpp / 8) * step;
	if (g_data.hit.side == WEST)
		g_data.sprites[3].adr += 1024 * (g_data.sprites[3].bpp / 8) * step;
}

void	jump_line_reverse_tex(int step)
{	
	if (g_data.hit.side == NORTH)
		g_data.sprites[0].adr -= 1024 * (g_data.sprites[0].bpp / 8) * step;
	if (g_data.hit.side == SOUTH)
		g_data.sprites[1].adr -= 1024 * (g_data.sprites[1].bpp / 8) * step;
	if (g_data.hit.side == EAST)
		g_data.sprites[2].adr -= 1024 * (g_data.sprites[2].bpp / 8) * step;
	if (g_data.hit.side == WEST)
		g_data.sprites[3].adr -= 1024 * (g_data.sprites[3].bpp / 8) * step;
}

void	increment_tex(int step)
{	
	if (g_data.hit.side == NORTH)
		g_data.sprites[0].adr += 4 * step;
	if (g_data.hit.side == SOUTH)
		g_data.sprites[1].adr += 4 * step;
	if (g_data.hit.side == EAST)
		g_data.sprites[2].adr += 4 * step;
	if (g_data.hit.side == WEST)
		g_data.sprites[3].adr += 4 * step;
}

void	decrement_tex(int step)
{	
	if (g_data.hit.side == NORTH)
		g_data.sprites[0].adr -= step * 4;
	if (g_data.hit.side == SOUTH)
		g_data.sprites[1].adr -= step * 4;
	if (g_data.hit.side == EAST)
		g_data.sprites[2].adr -= step * 4;
	if (g_data.hit.side == WEST)
		g_data.sprites[3].adr -= step * 4;
}
