/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moturki <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:21:35 by moturki           #+#    #+#             */
/*   Updated: 2023/11/03 14:39:29 by moturki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = s2;
	str[i] = 0;
	if (s1)
		free(s1);
	return (str);
}

int	init_info(t_list *info, int fd)
{
	info->curlen = 0;
	info->fd = fd;
	info->size = read(info->fd, info->buffer, BUFFER_SIZE);
	if (info->size < 1)
		return (0);
	return (1);
}

char	set_char(t_list *info)
{
	char	c;

	if (info->curlen >= info->size)
	{
		info->curlen = 0;
		info->size = read(info->fd, info->buffer, BUFFER_SIZE);
		if (info->size < 1)
			return (0);
	}
	c = info->buffer[info->curlen++];
	return (c);
}
