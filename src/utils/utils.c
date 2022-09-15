/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:58:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/15 19:07:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	width_height_map(void)
{
	int	i;

	i = 0;
	g_data.map.w = ft_strlen(g_data.map.tab[0]) - 3;
	while (g_data.map.tab[i])
		i++;
	g_data.map.h = i - 2;
}

// int		ft_spaceskip(char *line, int *i)
// {
// 	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
// 	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
// 		(*i)++;
// 	return (1);
// }

char	*ft_strndup(char *s1, int len)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
