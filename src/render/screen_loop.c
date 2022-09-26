/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:52:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/26 20:53:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	screen_loop(void)
{
	static int		tmp = 0;
	char			*adr_spr[4];
	double			pourcent;
	double			step;

	set_texture(adr_spr);
	g_data.img.adr = mlx_get_data_addr(g_data.img.ptr, &g_data.img.bpp, \
	&g_data.img.ll, &g_data.img.end);
	while (g_data.ray.i < W)
	{
		ray_rotate();
		ft_dir();
		ray_ver();
		ray_hor();
		g_data.utils.line_height = ft_size();
		g_data.wall.top = (H / 2) - (g_data.utils.line_height / 2);
		g_data.wall.bot = (H / 2) + (g_data.utils.line_height / 2);
		pourcent = ((g_data.wall.bot - g_data.wall.top) * 100 / 1024);
		step = round((1024.00 / pourcent) / 10.00);
		if (step <= 0 || pourcent >= 100)
			step = 1;
		draw_line(step);
		g_data.ray.i++;
		g_data.img.adr += 4;
		increment_tex(step);
		tmp += step;
		if (tmp >= 1024)
		{
			tmp = 0;
			reset_texture(adr_spr);
		}
	}
	mlx_put_image_to_window(g_data.mlx.ptr, g_data.win.ptr, \
	g_data.img.ptr, 0, 0);
	g_data.ray.i = 0;
	tmp = 0;
	reset_texture(adr_spr);
}

void	draw_line(double step)
{
	double		i;
	double		j;
	int			y;
	static int	color = 0;
	static int	tmp = 0;

	i = g_data.wall.top;
	j = g_data.wall.bot;
	y = 0;
	while (y < H)
	{
		if (y < i)
		{
			color = create_trgb(00, g_data.utils.params.colors_c[0], \
			g_data.utils.params.colors_c[1], g_data.utils.params.colors_c[2]);
			pixel_in_img(color);
		}
		else if (y >= round(i) && y <= round(j))
		{
			while (i < 0)
			{			
				if (tmp >= 1024)
				{
					jump_line_reverse_tex(tmp);
					tmp = 0;
				}
				jump_line_tex(step);
				tmp += step;
				i++;
			}
			draw_wall(color);
			jump_line_tex(step);
			tmp += step;
			if (tmp >= 1024)
			{
				jump_line_reverse_tex(tmp);
				tmp = 0;
			}
		}
		else
		{
			color = create_trgb(00, g_data.utils.params.colors_f[0], \
			g_data.utils.params.colors_f[1], g_data.utils.params.colors_f[2]);
			pixel_in_img(color);
		}
		y++;
		g_data.img.adr += W * 4;
	}
	jump_line_reverse_tex(tmp);
	tmp = 0;
	g_data.img.adr -= H * (W * 4);
}

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
