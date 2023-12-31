/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:49:56 by nraymond          #+#    #+#             */
/*   Updated: 2023/12/23 05:51:07 by nraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_last_empty(char **stash, char **buffer)
{
	char	*line;

	if (!*stash || !stash)
		return (free(*buffer), NULL);
	else if (*stash[0] == 0)
	{
		free(*buffer);
		return (free_all_stash(&*stash), NULL);
	}
	else
	{
		free(*buffer);
		line = ft_substr(*stash, 0, ft_strlen(*stash));
		return (free_all_stash(&*stash), line);
	}
}

int	get_end_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	update_buff(char **buff, char **line)
{
	char	*new;

	new = ft_strjoin(*buff, *line);
	free(*buff);
	*buff = new;
}

char	*extract_and_update_line(char **stash)
{
	char	*line;
	char	*updated_stash;

	line = ft_substr(*stash, 0, get_end_line(*stash));
	updated_stash = ft_substr
		(*stash, get_end_line(*stash) + 1, ft_strlen(*stash) + 1);
	free(*stash);
	*stash = updated_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	int			readc;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &buffer, 0) < 0)
		return (free_all_stash_fd(&stash[fd]), NULL);
	while (get_end_line(stash[fd]) == -1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (free_all_stash(&stash[fd]), NULL);
		readc = read(fd, buffer, BUFFER_SIZE);
		buffer[readc] = 0;
		if (readc <= 0)
			return (check_last_empty(&stash[fd], &buffer));
		else if (stash[fd] != NULL)
			update_buff(&stash[fd], &buffer);
		else
			stash[fd] = ft_substr(buffer, 0, ft_strlen(buffer));
		free(buffer);
	}
	return (extract_and_update_line(&stash[fd]));
}

/*
int	main(void)
{
	int fd = open("tests/bruh.txt", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 1;
	while (line)
	{
		printf("line %i = %s\n", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
