/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_col_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:06:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/22 17:09:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	nb_line(void)
{
	int	i;

	i = 0;
	while (g_data.map.tab[i])
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
	while (g_data.map.tab[i])
	{
		if (ft_strlen(g_data.map.tab[i]) >= len)
			len = ft_strlen(g_data.map.tab[i]);
		i++;
	}
	return (len - 3);
}
