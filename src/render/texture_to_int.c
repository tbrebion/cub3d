/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:46:53 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/16 17:16:02 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	tex_n_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.tex.n_adr;
	g_data.tex.n_adr++;
	r = (int)*g_data.tex.n_adr;
	g_data.tex.n_adr++;
	g = (int)*g_data.tex.n_adr;
	g_data.tex.n_adr++;
	b = (int)*g_data.tex.n_adr;
	g_data.tex.n_adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_s_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.tex.s_adr;
	g_data.tex.s_adr++;
	r = (int)*g_data.tex.s_adr;
	g_data.tex.s_adr++;
	g = (int)*g_data.tex.s_adr;
	g_data.tex.s_adr++;
	b = (int)*g_data.tex.s_adr;
	g_data.tex.s_adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_e_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.tex.e_adr;
	g_data.tex.e_adr++;
	r = (int)*g_data.tex.e_adr;
	g_data.tex.e_adr++;
	g = (int)*g_data.tex.e_adr;
	g_data.tex.e_adr++;
	b = (int)*g_data.tex.e_adr;
	g_data.tex.e_adr -= 3;
	return (create_trgb(t, r, g, b));
}

int	tex_w_to_int(void)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (int)*g_data.tex.w_adr;
	g_data.tex.w_adr++;
	r = (int)*g_data.tex.w_adr;
	g_data.tex.w_adr++;
	g = (int)*g_data.tex.w_adr;
	g_data.tex.w_adr++;
	b = (int)*g_data.tex.w_adr;
	g_data.tex.w_adr -= 3;
	return (create_trgb(t, r, g, b));
}
