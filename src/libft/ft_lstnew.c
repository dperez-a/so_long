/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:08:44 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:08:46 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*ptr;

	ptr = (void *)malloc(sizeof(struct s_list));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	ptr->content = content;
	return (ptr);
}
