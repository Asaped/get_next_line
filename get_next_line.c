#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	lst = {.fd = -1};
	char			c;
	char			*str;

	str = NULL;
	if (lst.fd != fd)
		if (!init_list(&lst, fd))
			return (0);
	c = set_char(&lst);
	while (c)
	{
		str = ft_strjoin(str, c);
		if (c == '\n')
			return (str);
		c = set_char(&lst);
	}
	return (str);
}
