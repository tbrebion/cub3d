/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/16 15:19:27 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int keysym);

void	init_mlx(void)
{
	g_data.game.mlx = mlx_init();
	garcol_add(g_data.game.mlx);
	g_data.game.win = mlx_new_window(g_data.game.mlx, 1920, 1080, "./cub3d");
	g_data.game.img = mlx_new_image(g_data.game.mlx, 1920, 1080);
	mlx_key_hook(g_data.game.win, &key_press, &g_data);
}

int	key_press(int keysym)
{
	// if (keysym == 53)
	// {
	// 	// ft_putstr_fd("\nOKOKOKOK\n", 0);
	// 	mlx_clear_window(g_data.game.mlx, g_data.game.win);
	// 	mlx_destroy_window(g_data.game.mlx, g_data.game.win);
	// 	garcol_free_all();
	// 	exit(0);
	// }
	if (keysym == 119)
	{
		g_data.ray.posx += 500;
		printf("\nPOS_X :%f\n", g_data.ray.posx);
	}
	return (1);
}
