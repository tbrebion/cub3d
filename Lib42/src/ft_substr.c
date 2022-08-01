/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:54:42 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/01 19:34:21 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_strnlen(char *s, int max)
{
	int	res;

	res = 0;
	while (s[res] && res < max)
		res++;
	return (res);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		res = ft_strdup("\0");
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strnlen(s, len) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[(unsigned int)i + start])
	{
		res[i] = s[start + (unsigned int)i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
