/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:10:45 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:10:47 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	return (ret);
}
