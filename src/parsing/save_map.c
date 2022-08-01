/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:37:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 15:33:31 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_lines(char **av)
{
	int		i;
	char	*line;
	int		fd;

	fd = 0;
	line = "ok";
	i = -1;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

char	*line_map(char **av)
{
	int		fd;
	char	*line;
	char	*save;
	int		i;
	int		j;

	fd = 0;
	i = 0;
	j = count_lines(av);
	save = NULL;
	line = " ";
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < j)
	{
		line = get_next_line(fd);
		save = ft_strjoin(save, line);
		free(line);
		i++;
	}
	close(fd);
	return (save);
}

char	**save_map(char *save)
{
	char	**ret;

	ret = ft_split(save, '\n');
	return (ret);
}
