/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:51:47 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/20 16:50:13 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_size(void);
static void draw_wall(int color/* , int y */);
static void	jump_line_tex(int tex, int step);
static void	jump_line_reverse_tex(int tex, int step);
static void	increment_tex(int tex);
static void	decrement_tex(int tex, int x);
// static void	mod_four(void);

void	ray_ver(void)
{
	double 	x;
	double 	y;

	x = floor(g_data.pos.x) + g_data.ray.v;
	y = g_data.pos.y + (x - g_data.pos.x) * (g_data.ray.y / g_data.ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < 1000)
	{
		if ((int)floor(y) > g_data.map.h || (int)(x - 1 + g_data.ray.v) > g_data.map.w)
		{
			g_data.hit.d = 1000000;
			break;
		}
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
	}
	g_data.hit.x = g_data.pos.x;
	g_data.hit.y = g_data.pos.y;
	g_data.hit.d = 10000000;
	g_data.hit.side = 0;
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
	int	tmp;

	tmp = 0;
	g_data.img.adr = mlx_get_data_addr(g_data.img.ptr, &g_data.img.bpp, &g_data.img.ll, &g_data.img.end);
	while (g_data.ray.i < W)
	{
		ray_rotate();
		ft_dir();
		ray_ver();
		ray_hor();
		g_data.utils.line_height = ft_size();
		g_data.wall.top = (H / 2) - (g_data.utils.line_height / 2);
		g_data.wall.bot = (H / 2) + (g_data.utils.line_height / 2);
		draw_line();
		g_data.ray.i++;
		g_data.img.adr += 4;
		increment_tex(g_data.hit.side);
		tmp++;
		if (tmp == 1024)
		{
			tmp = 0;
			decrement_tex(g_data.hit.side, 1024);
		}
		// if (g_data.wall.count >= 1024 * 4)
			// decrement_tex();
	}
	mlx_put_image_to_window(g_data.mlx.ptr, g_data.win.ptr, g_data.img.ptr, 0, 0);
	g_data.ray.i = 0;
	decrement_tex(g_data.hit.side, tmp);
	// decrement_tex()
}

void draw_line(void)
{
	// int	line_height;
	int	i;
	int	j;
	int	y;
	int	color;
	
	int	tmp = 0;
	int	step;

	// line_height = ft_size();
	// g_data.wall.top = (H / 2) - (g_data.utils.line_height / 2);
	// g_data.wall.bot = (H / 2) + (g_data.utils.line_height / 2);
	i = g_data.wall.top;
	j = g_data.wall.bot;
	if (j >= H)
		j = H - 1;
	step = 1024 / (j - i);
	y = 0;
	while (y < H)
	{
		if (y < i)
		{
			color = create_trgb(00, g_data.utils.params.colors_c[0], g_data.utils.params.colors_c[1], g_data.utils.params.colors_c[2]);
			pixel_in_img(color);
		}
		else if (y >= i && y <= j)
		{
			draw_wall(color/* , y */);
			i++;
			if (tmp <= 1024)
				jump_line_tex(g_data.hit.side, step);
			else
			{
				jump_line_reverse_tex(g_data.hit.side, step);
				tmp = 0;
			}
			tmp += step;
		}
		else
		{
			color = create_trgb(00, g_data.utils.params.colors_f[0], g_data.utils.params.colors_f[1], g_data.utils.params.colors_f[2]);
			pixel_in_img(color);
		}
		y++;
		g_data.img.adr += W * 4;
	}
	jump_line_reverse_tex(g_data.hit.side, tmp);
	g_data.img.adr -= H * (W * 4);
}

static void draw_wall(int color/* , int y */)
{
	if (g_data.hit.side == NORTH)
		color = tex_n_to_int();
	else if (g_data.hit.side == SOUTH)
		color = tex_s_to_int();
	else if (g_data.hit.side == EAST)
		color = tex_e_to_int();
	else if (g_data.hit.side == WEST)
		color = tex_w_to_int();
	pixel_in_img(color);
}

static int	ft_size(void)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)g_data.ray.i / (W / 2) - 1);
	fisheye *= 28 * PI / 180;
	correc = (double)g_data.hit.d * cos(fisheye);
	return (floor(H / correc));
}

static void	jump_line_tex(int tex, int step)
{
	if (tex == NORTH)
		g_data.sprites[0].adr += 1024 * (g_data.sprites[0].bpp / 8) * step;
	if (tex == SOUTH)
		g_data.sprites[1].adr += 1024 * (g_data.sprites[1].bpp / 8) * step;
	if (tex == EAST)
		g_data.sprites[2].adr += 1024 * (g_data.sprites[2].bpp / 8) * step;
	if (tex == WEST)
		g_data.sprites[3].adr += 1024 * (g_data.sprites[3].bpp / 8) * step;
}

static void	jump_line_reverse_tex(int tex, int step)
{	
	if (tex == NORTH)
		g_data.sprites[0].adr -= (1024 * g_data.sprites[0].bpp / 8) * step;// * (1024 / step);
	if (tex == SOUTH)
		g_data.sprites[1].adr -= (1024 * g_data.sprites[1].bpp / 8) * step;// * (1024 / step);
	if (tex == EAST)
		g_data.sprites[2].adr -= (1024 * g_data.sprites[2].bpp / 8) * step;// * (1024 / step);
	if (tex == WEST)
		g_data.sprites[3].adr -= (1024 * g_data.sprites[3].bpp / 8) * step;// * (1024 / step);
}

static void	increment_tex(int tex)
{	
	if (tex == NORTH)
		g_data.sprites[0].adr += 4;
	if (tex == SOUTH)
		g_data.sprites[1].adr += 4;
	if (tex == EAST)
		g_data.sprites[2].adr += 4;
	if (tex == WEST)
		g_data.sprites[3].adr += 4;
}

static void	decrement_tex(int tex, int x)
{	
	if (tex == NORTH)
		g_data.sprites[0].adr -= x * 4;
	if (tex == SOUTH)
		g_data.sprites[1].adr -= x * 4;
	if (tex == EAST)
		g_data.sprites[2].adr -= x * 4;
	if (tex == WEST)
		g_data.sprites[3].adr -= x * 4;
}

// static void	mod_four(void)
// {
// 	int	mod;

// 	mod = g_data.wall.count % 4;
// 	if (mod)
// 	{		
// 		g_data.sprites[0].adr -= mod;
// 		g_data.sprites[1].adr -= mod;
// 		g_data.sprites[2].adr -= mod;
// 		g_data.sprites[3].adr -= mod;
// 		g_data.wall.count -= mod;
// 	}
// }
