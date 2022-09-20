/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:14:01 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/20 12:15:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_char(char c, char *str)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i])
	{
		if (str[i] == c)
			ct++;
		i++;
	}
	return (ct);
}
