/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 17:26:53 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	g_data;

int	ft_close(void)
{
	mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_destroy_window(g_data.mlx.ptr, g_data.win.ptr);
	garcol_free_all();
	exit(0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	check_init_file(ac, av);
	g_data.pos.x = 300;
	g_data.pos.y = 300;
	init_mlx();

	///////////////////////////////////
	draw_map();	
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x, g_data.pos.y, 0x00FF0000);
	mlx_hook(g_data.win.ptr, 2, 0, &key_press, &g_data);
	mlx_hook(g_data.win.ptr, 17, 0, &ft_close, &g_data);
	// mlx_key_hook(g_data.win.ptr, &key_press, &g_data);
	////////////////////////////////////////////////////////////////////
	mlx_loop(g_data.mlx.ptr);
	garcol_free_all();
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	(void)envp;
// 	check_init_file(ac, av);
// 	init_mlx();
// 	mlx_loop(g_data.mlx.ptr);
// 	garcol_free_all();
// 	return (0);
// }
