/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:57:22 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/01 19:33:53 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trimlen(char *str, char *set)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	k = ft_strlen(str);
	while (str[i] && isset(str[i], set) == 1)
	{
		i++;
		if (i == ft_strlen(str))
			return (0);
	}
	while (str[k - 1] && isset(str[k - 1], set) == 1)
	{
		k--;
		j++;
	}
	len = ft_strlen(str) - i - j;
	return (len);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*res;
	int		trimlen;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	trimlen = ft_trimlen(s1, set);
	res = malloc(sizeof(char) * (trimlen + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] && isset(s1[j], set) == 1)
		j++;
	while (s1[j] && i < trimlen)
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
