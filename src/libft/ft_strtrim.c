/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:12:03 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:12:05 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_gtstart(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_gtend(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_gtstart(s1, set);
	end = ft_gtend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * end - start + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, (end - start) + 1);
	return (str);
}
