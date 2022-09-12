/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/12 21:28:06 by tbrebion         ###   ########.fr       */
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
	mlx_destroy_display(g_data.mlx.ptr);
	garcol_free_all();
	exit(0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	// int	i = 3;
	(void)envp;
	check_init_file(ac, av);
	width_height_map();
	init();
	init_mlx();
	// g_data.win.x = for_win(g_data.map.tab[i], &i);
	// g_data.win.y = for_win(g_data.map.tab[i], &i);
	// printf("////////\nwin x : %d\nwin y : %d\n///////////\n", g_data.win.x, g_data.win.y);

	///////////////////////////////////
	draw();
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
	////////////////////////////////////////////////////////////////////
	// screen_loop();
	mlx_hook(g_data.win.ptr, 2, (1L << 0), ft_key, &g_data);
	mlx_hook(g_data.win.ptr, 17, 0, &ft_close, &g_data);
	// mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_loop(g_data.mlx.ptr);
	garcol_free_all();
	return (0);
}

static void	init(void)
{
	// int	i;

	// i = 1;
	// g_data.win.x = for_win(g_data.map.tab[i], &i);
	// g_data.win.y = for_win(g_data.map.tab[i], &i);
	// printf("////////\nwin x : %d\nwin y : %d\n///////////\n", g_data.win.x, g_data.win.y);
	g_data.ray.x = 0;
	g_data.ray.y = 0;
	g_data.ray.v = 0;
	g_data.ray.w = 0;
	g_data.ray.i = 0;
	g_data.hit.x = 0;
	g_data.hit.y = 0;
	g_data.hit.d = 0;
	// ft_rotate(1);
	// ft_ad(1);
	// ft_ws(1);
	// ft_rotate(-1);
	// ft_ad(-1);
	// ft_ws(-1);
	// screen_loop();
}
