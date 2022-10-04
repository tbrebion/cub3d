/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:29:15 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/04 11:57:02 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	garcol_add(void *var)
{
	ft_lstadd_back(g_data.garbage, ft_lstnew(var));
}

char	**garcol_split(char *str, char lim)
{
	char	**split;
	int		i;

	split = ft_split(str, lim);
	if (!split)
		return (NULL);
	garcol_add(split);
	i = 0;
	while (split[i])
	{
		garcol_add(split[i]);
		i++;
	}
	return (split);
}

void	garcol_free_all(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *g_data.garbage;
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	free(g_data.garbage);
}
