/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:29:15 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/04 16:58:58 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	garcol_add(void *var)
{
	ft_lstadd_back(g_data.garbage, ft_lstnew(var));
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
