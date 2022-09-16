/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:11:53 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/16 16:57:57 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(void)
{
	int	bpp[4];
	int	sl[4];
	int	end[4];
	
	g_data.tex.n = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.NO_path, g_data.win.w, g_data.win.h);
	if (!g_data.tex.n)
	{
		printf("Error : texture NO not found\n");
		ft_close();
	}
	g_data.tex.s = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.SO_path, g_data.win.w, g_data.win.h);
	if (!g_data.tex.s)
	{
		printf("Error : texture SO not found\n");
		ft_close();
	}
	g_data.tex.e = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.EA_path, g_data.win.w, g_data.win.h);
	if (!g_data.tex.e)
	{
		printf("Error : texture EA not found\n");
		ft_close();
	}
	g_data.tex.w = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.WE_path, g_data.win.w, g_data.win.h);
	if (!g_data.tex.w)
	{
		printf("Error : texture WE not found\n");
		ft_close();
	}
	g_data.tex.n_adr = mlx_get_data_addr(g_data.tex.n, &bpp[0], &sl[0], &end[0]);
	g_data.tex.s_adr = mlx_get_data_addr(g_data.tex.s, &bpp[1], &sl[1], &end[1]);
	g_data.tex.e_adr = mlx_get_data_addr(g_data.tex.e, &bpp[2], &sl[2], &end[2]);
	g_data.tex.w_adr = mlx_get_data_addr(g_data.tex.w, &bpp[3], &sl[3], &end[3]);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_in_img(int color)
{
	*(int *)g_data.img.adr = color;
}
