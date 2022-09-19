/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/19 18:43:41 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init(void);

t_data	g_data;

int	ft_close(void)
{
	mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_destroy_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.img.ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.sprites[0].ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.sprites[1].ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.sprites[2].ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.sprites[3].ptr);
	mlx_destroy_display(g_data.mlx.ptr);
	garcol_free_all();
	exit(0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	check_init_file(ac, av);
	width_height_map();
	init();
	init_mlx();
	screen_loop();
	draw();
	player_mini_map();
	mlx_hook(g_data.win.ptr, 2, (1L << 0), ft_key, &g_data);
	mlx_hook(g_data.win.ptr, 17, 0, &ft_close, &g_data);
	mlx_loop(g_data.mlx.ptr);
	garcol_free_all();
	return (0);
}

static void	init(void)
{
	g_data.ray.x = 0;
	g_data.ray.y = 0;
	g_data.ray.v = 0;
	g_data.ray.w = 0;
	g_data.ray.i = 0;
	g_data.hit.x = 0;
	g_data.hit.y = 0;
	g_data.hit.d = 0;
	g_data.wall.count = 0;
	// g_data.sprites[0].count = 0;
	// g_data.sprites[1].count = 0;
	// g_data.sprites[2].count = 0;
	// g_data.sprites[3].count = 0;
}

void	player_mini_map(void)
{
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, (g_data.pos.x * SIZE) + 1, g_data.pos.y * SIZE, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, (g_data.pos.x * SIZE) + 2, g_data.pos.y * SIZE, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, (g_data.pos.x * SIZE) - 1, g_data.pos.y * SIZE, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, (g_data.pos.x * SIZE) - 2, g_data.pos.y * SIZE, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, (g_data.pos.y * SIZE) + 1, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, (g_data.pos.y * SIZE) + 2, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, (g_data.pos.y * SIZE) + 1, 0x00FFFFFF);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, (g_data.pos.y * SIZE) - 2, 0x00FFFFFF);	
}
