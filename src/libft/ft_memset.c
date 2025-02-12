/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:09:34 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:09:49 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*p;

	p = (unsigned char *) b;
	while (0 < len--)
	{
		*p++ = (unsigned char) c;
	}
	return (b);
}
