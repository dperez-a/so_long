/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:12:12 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:12:14 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	sbstr = (char *)malloc(sizeof(char) * (len + 1));
	s += start;
	if (!sbstr)
		return (0);
	ft_strlcpy(sbstr, s, len + 1);
	return (sbstr);
}
