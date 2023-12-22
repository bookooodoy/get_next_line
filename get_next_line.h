#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// main
char	*get_next_line(int fd);
int	get_end_line(char *line);
void	update_buff(char **buff, char **line);
char	*read_line(int fd);

//utils
size_t	ft_strlen(char const *s);
void	ft_bzero(char **s, size_t n);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

#endif
