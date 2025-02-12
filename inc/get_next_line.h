/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani_mm__ <dani_mm__@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:23 by dani_mm__         #+#    #+#             */
/*   Updated: 2024/05/15 12:15:25 by dani_mm__        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd, char **to);
char	*gn_reader(int fd, char *read_res, char **buffer);
char	*append_line(int nl_index, char **buffer);
void	free_str(char **ptr);
/*Helpers*/
char	*gn_strdup(char *str);
size_t	gn_strlen(char *s);
int		gn_strchr(char *str, char n);
char	*gn_strjoin(char *s1, char *s2);
char	*gn_substr(char *s, unsigned int start, size_t len);
char	*append_line(int nl_index, char **buffer);
#endif
