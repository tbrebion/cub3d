/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:54:03 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/13 17:56:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_stock(void)
{
	g_data.stock[g_data.ray.i].x = g_data.hit.x;
	g_data.stock[g_data.ray.i].y = g_data.hit.y;
	g_data.stock[g_data.ray.i].d = g_data.hit.d;
}
