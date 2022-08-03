/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:20:51 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/03 12:34:40 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_file_lines(char **av);

char	**save_file(char **av)
{
	int		fd;
	char	**save;
	int		i;
	int		j;

	i = 0;
	j = count_file_lines(av);
	save = malloc(sizeof(char *) * (count_file_lines(av) + 1));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < j)
	{
		save[i] = get_next_line(fd);
		i++;
	}
	save[i] = NULL;
	close(fd);
	return (save);
}

static int	count_file_lines(char **av)
{
	int		i;
	char	*line;
	int		fd;

	line = "ok";
	i = 0;
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
