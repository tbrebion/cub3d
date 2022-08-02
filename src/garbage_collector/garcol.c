/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:29:15 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/02 12:06:02 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	*garcol_add(void *var, size_t size)
{
	var = malloc(size);
	if (!var)
		return (NULL);
	ft_lstadd_back(g_data.garbage, ft_lstnew(var));
	return (var);
}

// void	*garcol_free_one(void *var)
// {
// 	t_list	*lst;

// 	lst = *g_data.garbage;
// 	while (lst)
// 	{
// 		if (lst->content == var)
// 		{
// 			while (lst->next)
// 			{

// 			}
// 		}
// 		lst = lst->next;
// 	}
// }

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
}
