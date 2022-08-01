/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:37:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/01 18:16:29 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_lines(char **av)
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
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

char	**save_map(char **av)
{
	int		fd;
	char	**save;
	int		i;
	int		j;

	i = 0;
	j = count_lines(av);
	save = malloc(sizeof(char *) * (count_lines(av) + 1));
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

// char	**save_map(char *save)
// {
// 	char	**ret;

// 	if (!save)
// 		return (NULL);
// 	ret = ft_split(save, '\n');
// 	return (ret);
// }
