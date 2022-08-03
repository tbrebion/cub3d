/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:37:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 15:48:05 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	del_last_backslash_n(char *str);
static int	count_map_lines(char **file);
static char	*get_spaces_lines(int n, char **save);
static char	*add_end_spaces(char *str);

char	**save_map(char **file)
{
	char	**save;
	char	*tmp;
	char	*tmp1;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = first_map_line(file);
	j = (count_map_lines(file) - k) + 1;
	save = malloc(sizeof(char *) * (j + 3));
	save[0] = get_spaces_lines(0, save);
	while (i < j)
	{
		tmp1 = ft_strdup(file[k]);
		tmp =  ft_strjoin(ft_strdup(" "), tmp1);
		free(tmp1);
		del_last_backslash_n(tmp);
		save[i] = add_end_spaces(tmp);
		i++;
		k++;
	}
	save[i] = get_spaces_lines(i, save);
	i++;
	save[i] = NULL;
	return (save);
}

static int	count_map_lines(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strlen(file[i]) > g_data.game.max_len)
			g_data.game.max_len = ft_strlen(file[i]);
		i++;
	}
	return (i);
}

static void	del_last_backslash_n(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	j--;
	if (str[j] == '\n')
		str[j] = '\0';
}

static char	*get_spaces_lines(int n, char **save)
{
	int	i;

	i = 0;
	save[n] = malloc(g_data.game.max_len + 3);
	while (i <= g_data.game.max_len)
	{
		save[n][i] = ' ';
		i++;
	}
	save[n][i] = ' ';
	i++;
	save[n][i] = '\0';
	return (save[n]);
}

static char	*add_end_spaces(char *str)
{
	int	i;
	int prev_len;

	i = 0;
	prev_len = ft_strlen(str);
	while (i++ <= (g_data.game.max_len - prev_len) + 1)
		str = ft_strjoin(str, " "); 
	return (str);
}
