/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:42:32 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/23 20:56:20 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// main
char	*check_last_empty(char **stash, char **buffer);
char	*get_next_line(int fd);
int		get_end_line(char *line);
void	update_buff(char **buff, char **line);
char	*read_line(int fd, char **stash);
void	free_all_stash(char **stash);

//utils
size_t	ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
