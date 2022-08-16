/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_col_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:06:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/16 18:24:41 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	nb_line(void)
{
	int	i;

	i = 0;
	while (g_data.game.map[i])
		i++;
	return (i - 2);
}

int	nb_col(void)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (g_data.game.map[i])
	{
		if (ft_strlen(g_data.game.map[i]) >= len)
			len = ft_strlen(g_data.game.map[i]);
		i++;
	}
	return (len - 3);
}
