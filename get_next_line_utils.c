#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(char **s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
		*s[index++] = '\0';
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	tab = (char *)malloc(size * nmemb);
	if (!(tab))
		return (NULL);
	ft_bzero(&tab, (nmemb * size));
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	new_string = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(new_string))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_string[i] = s1[i];
		i++;
	}
	while (k < ft_strlen(s2))
	{
		new_string[i + k] = s2[k];
		k++;
	}
	new_string[i + k] = '\0';
	return (new_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*to_ret;
	size_t	index;

	index = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	to_ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(to_ret))
		return (NULL);
	while (index < len)
	{
		to_ret[index] = s[start + index];
		index++;
	}
	to_ret[index] = '\0';
	return (to_ret);
}
