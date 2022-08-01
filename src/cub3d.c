/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 18:21:05 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	(void)envp;
	check_and_init(ac, av, &game);
	free_split(game.map);
	return (0);
}