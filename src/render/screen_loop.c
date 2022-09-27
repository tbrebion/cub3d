/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:52:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/27 14:12:12 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void		draw_line(double step);
static void		loop(int tmp, char *adr_spr[4], double pourcent, double step);
static int		draw_loop(double *i, double step, int color, int tmp);
static void		draw_helper(int color, int sky_ground);

void	screen_loop(void)
{
	int				tmp;
	char			*adr_spr[4];
	double			pourcent;
	double			step;

	tmp = 0;
	set_texture(adr_spr);
	g_data.img.adr = mlx_get_data_addr(g_data.img.ptr, &g_data.img.bpp, \
	&g_data.img.ll, &g_data.img.end);
	pourcent = 0.0;
	step = 0.0;
	loop(tmp, adr_spr, pourcent, step);
	mlx_put_image_to_window(g_data.mlx.ptr, g_data.win.ptr, \
	g_data.img.ptr, 0, 0);
	g_data.ray.i = 0;
	tmp = 0;
	reset_texture(adr_spr);
}

static void	loop(int tmp, char *adr_spr[4], double pourcent, double step)
{	
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
}

static void	draw_line(double step)
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
			draw_helper(color, 1);
		else if (y >= round(i) && y <= round(j))
			tmp = draw_loop(&i, step, color, tmp);
		else
			draw_helper(color, 2);
		y++;
		g_data.img.adr += W * 4;
	}
	jump_line_reverse_tex(tmp);
	tmp = 0;
	g_data.img.adr -= H * (W * 4);
}

static int	draw_loop(double *i, double step, int color, int tmp)
{
	while ((*i) < 0)
	{			
		if (tmp >= 1024)
		{
			jump_line_reverse_tex(tmp);
			tmp = 0;
		}
		jump_line_tex(step);
		tmp += step;
		(*i)++;
	}
	draw_wall(color);
	jump_line_tex(step);
	tmp += step;
	if (tmp >= 1024)
	{
		jump_line_reverse_tex(tmp);
		tmp = 0;
	}
	return (tmp);
}

static void	draw_helper(int color, int sky_ground)
{
	if (sky_ground == 1)
	{
		color = create_trgb(00, g_data.utils.params.colors_c[0], \
		g_data.utils.params.colors_c[1], g_data.utils.params.colors_c[2]);
		pixel_in_img(color);
	}
	else if (sky_ground == 2)
	{		
		color = create_trgb(00, g_data.utils.params.colors_f[0], \
		g_data.utils.params.colors_f[1], g_data.utils.params.colors_f[2]);
		pixel_in_img(color);
	}
}
