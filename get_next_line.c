/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moturki <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:58 by moturki           #+#    #+#             */
/*   Updated: 2023/10/31 10:21:25 by moturki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	info = {.fd = -1};
	char			*str;
	char			c;

	str = NULL;
	if (info.fd != fd)
		if (!init_info(&info, fd))
			return (NULL);
	c = set_char(&info);
	while (c)
	{
		str = ft_strjoin(str, c);
		if (c == '\n')
			return (str);
		c = set_char(&info);
	}
	return (str);
}
