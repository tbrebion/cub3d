/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:05:27 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 15:27:26 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	maps_begin(char *str);

int	first_map_line(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (maps_begin(file[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	maps_begin(char *str)
{
	int i;
	int	one;

	i = 0;
	one = 0;
	while(str[i])
	{
		if (str[i] == '1')
		{
			i++;
			one++;
		}
		else if (str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	if (one == 0)
		return (0);
	return (1);
}
