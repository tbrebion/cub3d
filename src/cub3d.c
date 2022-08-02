/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/02 15:11:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	g_data;

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	check_and_init(ac, av);
	free_split(g_data.game.map, 1);
	return (0);
}







//	TEST MAIN FOR GARCOL
// int	main(void)
// {
// 	g_data.garbage = malloc(sizeof(t_list *));
// 	*g_data.garbage = NULL;
// 	////////////////////////////////////////////////////////
// 	char	*str;
// 	str = NULL;
// 	str = garcol_add(str, sizeof(char) * 44);
// 	if (!str)
// 		return (1);
// 	int		i = 0;
// 	while (i < 43)
// 	{
// 		str[i] = i + 48;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	printf("str = [%s]\n", str);
// 	/////////////////////////////////////////////////////////
// 	char	**str_tab;
// 	str_tab = NULL;
// 	str_tab = garcol_add(str_tab, sizeof(char *) * 3);
// 	if (!str_tab)
// 		return (1);
// 	str_tab[0] = "Hello world\n";
// 	str_tab[1] = "What's up\n";
// 	str_tab[2] = "oeoeoe\n";
// 	printf("%s%s%s", str_tab[0], str_tab[1], str_tab[2]);
// 	//////////////////////////////////////////////////////////
// 	garcol_free_all();
// 	free(g_data.garbage);
// 	return (0);
// }
