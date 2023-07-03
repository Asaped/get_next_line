#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		len;
	int		pos;
}			t_list;

char	*get_next_line(int fd);

int		init_list(t_list *lst, int fd);

char	set_char(t_list *lst);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *s1, char s2);

#endif
