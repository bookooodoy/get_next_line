#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

void	free_all_stash(char **stash)
{
	if (!*stash)
		return ;
	free(*stash);
}

int	get_end_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	update_buff(char **stash, char **line)
{
	char	*new;

	new = ft_strjoin(*stash, *line);
	free(*stash);

	*stash = new;
}

char	*read_line(int fd, char **stash)
{
	char	*buff;
	int	readc;

	while (get_end_line(stash) == -1)
	{
		buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buff)
			return (ft_clear_all_stash(stash), NULL);
		readc = read(fd, buff, BUFFER_SIZE);
		if (readc <= 0) // file is empty, no /n || read error
			return (free_all_stash(stash), free(buff), NULL);
		buff[readc] = 0;
		update_buff(stash, &buff);
		free(buff);
	}
	return (free(line));
}

char	*get_next_line(int fd)
{
	static char		*stash[1024];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (free_all_stash(line), NULL);
	stash[fd] = read_line(fd);
	if (!buffer || !*buffer)
		return (get_next_line(-1));
	if (get_end_line(buffer) == -1)
	{
		line[fd] = ft_substr(buffer, 0, ft_strlen(buffer));
		return (free(buffer), line[fd]);
	}
	else
		line[fd] = ft_substr(buffer, 0, get_end_line(buffer));
	return (free(buffer), line[fd]);
}

int	main(void)
{
	int fd = open("tests/test.txt", O_RDONLY);
	char *line = get_next_line(fd); 
	int i = 1;
	while (i < 15)
	{
		printf("line %i = %s\n", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("line %i = %s\n", i, line);
	free(line);
	close(fd);
	return (0);
}
