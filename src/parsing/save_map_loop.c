/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:05:11 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 16:24:46 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*save_map_loop(char **save, char **file, int k, int i)
{
	char	*tmp;
	char	*tmp_dos;

	tmp_dos = ft_strdup(file[k]);
	tmp = ft_strjoin(ft_strdup(" "), tmp_dos);
	free(tmp_dos);
	del_last_backslash_n(tmp);
	save[i] = add_end_spaces(tmp);
	return (save[i]);
}
