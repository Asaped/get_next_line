#include "get_next_line.h"

int	init_list(t_list *lst, int fd)
{
	lst->pos = 0;
	lst->fd = fd;
	lst->len = read(lst->fd, lst->buffer, BUFFER_SIZE);
	if (lst->len < 1)
		return (0);
	else
		return (1);
}

char	set_char(t_list *lst)
{
	char	c;

	if (lst->pos >= lst->len)
	{
		lst->pos = 0;
		lst->len = read(lst->fd, lst->buffer, BUFFER_SIZE);
		if (lst->len < 1)
			return (0);
	}
	c = lst->buffer[lst->pos++];
	return (c);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
		str[i++] = s1[j++];
	str[i] = s2;
	str[i + 1] = 0;
	if (s1)
		free(s1);
	return (str);
}
