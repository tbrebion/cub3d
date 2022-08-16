/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/16 19:41:29 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	g_data;

// int	main(int ac, char **av, char **envp)
// {
// 	(void)envp;
// 	check_init_file(ac, av);
// 	init_mlx();
// 	mlx_loop(g_data.game.mlx);
// 	garcol_free_all();
// 	return (0);
// }


int	main(int ac, char **av, char **envp)
{
	(void)envp;
	check_init_file(ac, av);
	g_data.ray.posx = 300;
	g_data.ray.posy = 300;
	init_mlx();

	////////////////////////////////////////////////////////////////////
	// int	mapsizeX = 8;
	// int	mapsizeY = 8;
	// int	square_size = 64;
	printf("\nline %d\ncol %d\n", nb_line(), nb_col());
	draw_map();	
	mlx_pixel_put(g_data.game.mlx, g_data.game.win, g_data.ray.posx, g_data.ray.posy, 0x00FF0000);
	mlx_key_hook(g_data.game.win, &key_press, &g_data);

	////////////////////////////////////////////////////////////////////
	mlx_loop(g_data.game.mlx);
	garcol_free_all();
	return (0);
}
// 	TEST MAIN FOR GARCOL
// int	main(void)
// {
// 	g_data.garbage = malloc(sizeof(t_list *));
// 	*g_data.garbage = NULL;
// 	////////////////////////////////////////////////////////
// 	char	*str;
// 	str = NULL;
// 	str = garcol_add(str, sizeof(char) * 44);
// 	if (!str)
// 		return (1);
// 	int		i = 0;
// 	while (i < 43)
// 	{
// 		str[i] = i + 48;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	printf("str = [%s]\n", str);
// 	/////////////////////////////////////////////////////////
// 	str = garcol_add(str, 4096);
// 	i = 0;
// 	char	*abc = "abcdefg";
// 	while (abc[i])
// 	{
// 		str[i] = abc[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	printf("str = [%s]\n", str);
// 	/////////////////////////////////////////////////////////
// 	char	**str_tab;
// 	str_tab = NULL;
// 	str_tab = garcol_add(str_tab, sizeof(char *) * 3);
// 	if (!str_tab)
// 		return (1);
// 	str_tab[0] = "Hello world\n";
// 	str_tab[1] = "What's up\n";
// 	str_tab[2] = "oeoeoe\n";
// 	printf("%s%s%s", str_tab[0], str_tab[1], str_tab[2]);
// 	//////////////////////////////////////////////////////////
// 	garcol_free_all();
//	// free(g_data.garbage);
// 	return (0);
// }
