/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:46:53 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/20 14:04:20 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	tex_n_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.sprites[0].adr;
	// g_data.sprites[0].adr++;
	r = (int)*g_data.sprites[0].adr;
	// g_data.sprites[0].adr++;
	g = (int)*g_data.sprites[0].adr;
	// g_data.sprites[0].adr++;
	b = (int)*g_data.sprites[0].adr;
	// g_data.sprites[0].adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_s_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.sprites[1].adr;
	// g_data.sprites[1].adr++;
	r = (int)*g_data.sprites[1].adr;
	// g_data.sprites[1].adr++;
	g = (int)*g_data.sprites[1].adr;
	// g_data.sprites[1].adr++;
	b = (int)*g_data.sprites[1].adr;
	// g_data.sprites[1].adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_e_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.sprites[2].adr;
	// g_data.sprites[2].adr++;
	r = (int)*g_data.sprites[2].adr;
	// g_data.sprites[2].adr++;
	g = (int)*g_data.sprites[2].adr;
	// g_data.sprites[2].adr++;
	b = (int)*g_data.sprites[2].adr;
	// g_data.sprites[2].adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_w_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.sprites[3].adr;
	// g_data.sprites[3].adr++;
	r = (int)*g_data.sprites[3].adr;
	// g_data.sprites[3].adr++;
	g = (int)*g_data.sprites[3].adr;
	// g_data.sprites[3].adr++;
	b = (int)*g_data.sprites[3].adr;
	// g_data.sprites[3].adr -= 3;
	return (create_trgb(t, r, g, b));
}
