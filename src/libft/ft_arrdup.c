/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:23 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 11:45:25 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (!str)
		return (NULL);
	while (arr[i])
	{
		str[i] = ft_strdup(arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
