/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:07:59 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/27 12:08:49 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(int color)
{
	if (g_data.hit.side == NORTH)
		color = tex_n_to_int();
	if (g_data.hit.side == SOUTH)
		color = tex_s_to_int();
	if (g_data.hit.side == EAST)
		color = tex_e_to_int();
	if (g_data.hit.side == WEST)
		color = tex_w_to_int();
	pixel_in_img(color);
}

double	ft_size(void)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)g_data.ray.i / (W / 2) - 1);
	fisheye *= 30 * PI / 180;
	correc = (double)g_data.hit.d * cos(fisheye);
	return (floor(H / correc));
}
