/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:37:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 12:43:06 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	del_last_backslash_n(char *str);
static int	count_lines(char **av);
static char	*get_spaces_lines(int n, char **save);
static char	*add_end_spaces(char *str);

char	**save_map(char **av)
{
	int		fd;
	char	**save;
	char	*tmp;
	char	*tmp1;
	int		i;
	int		j;

	i = 1;
	j = count_lines(av) + 1;
	save = malloc(sizeof(char *) * (count_lines(av) + 3));
	save[0] = get_spaces_lines(0, save);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < j)
	{
		tmp1 = get_next_line(fd);
		tmp =  ft_strjoin(ft_strdup(" "), tmp1);
		free(tmp1);
		del_last_backslash_n(tmp);
		save[i] = add_end_spaces(tmp);
		i++;
	}
	save[i] = get_spaces_lines(i, save);
	i++;
	save[i] = NULL;
	close(fd);
	return (save);
}

static int	count_map_lines(char **av)
{
	int		i;
	char	*line;
	int		fd;

	line = "ok";
	i = -1;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > g_data.game.max_len)
			g_data.game.max_len = ft_strlen(line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
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
