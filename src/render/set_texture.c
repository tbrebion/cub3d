/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:11:53 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/19 16:49:13 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(void)
{
	g_data.sprites[0].ptr = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.NO_path, &g_data.sprites[0].x, &g_data.sprites[0].y);
	if (!g_data.sprites[0].ptr)
	{
		printf("Error : texture NO not found\n");
		ft_close();
	}
	g_data.sprites[1].ptr = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.SO_path, &g_data.sprites[1].x, &g_data.sprites[1].y);
	if (!g_data.sprites[1].ptr)
	{
		printf("Error : texture SO not found\n");
		ft_close();
	}
	g_data.sprites[2].ptr = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.EA_path, &g_data.sprites[2].x, &g_data.sprites[2].y);
	if (!g_data.sprites[2].ptr)
	{
		printf("Error : texture EA not found\n");
		ft_close();
	}
	g_data.sprites[3].ptr = mlx_xpm_file_to_image(g_data.mlx.ptr, g_data.utils.params.WE_path, &g_data.sprites[3].x, &g_data.sprites[3].y);
	if (!g_data.sprites[3].ptr)
	{
		printf("Error : texture WE not found\n");
		ft_close();
	}
	g_data.sprites[0].adr = mlx_get_data_addr(g_data.sprites[0].ptr, &g_data.sprites[0].bpp, &g_data.sprites[0].ll, &g_data.sprites[0].end);
	g_data.sprites[1].adr = mlx_get_data_addr(g_data.sprites[1].ptr, &g_data.sprites[1].bpp, &g_data.sprites[1].ll, &g_data.sprites[1].end);
	g_data.sprites[2].adr = mlx_get_data_addr(g_data.sprites[2].ptr, &g_data.sprites[2].bpp, &g_data.sprites[2].ll, &g_data.sprites[2].end);
	g_data.sprites[3].adr = mlx_get_data_addr(g_data.sprites[3].ptr, &g_data.sprites[3].bpp, &g_data.sprites[3].ll, &g_data.sprites[3].end);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_in_img(int color)
{
	*(int *)g_data.img.adr = color;
}

int	text_in_img(int i)
{
	int	color;

	color = 0;
	if (i == 0)
	{
		color = tex_n_to_int();
		// g_data.sprites[0].adr += 4;// g_data.sprites[0].x * (g_data.sprites[0].bpp / 8);
	}
	else if (i == 1)
	{
		color = tex_s_to_int();
		// g_data.sprites[1].adr += 4;// g_data.sprites[1].x * (g_data.sprites[1].bpp / 8);
	}
	else if (i == 2)
	{
		color = tex_e_to_int();
		// g_data.sprites[2].adr += 4;// g_data.sprites[2].x * (g_data.sprites[2].bpp / 8);
	}
	else if (i == 3)
	{
		color = tex_w_to_int();
		// g_data.sprites[3].adr += 4;// g_data.sprites[3].x * (g_data.sprites[3].bpp / 8);
	}
	return (color);
}
