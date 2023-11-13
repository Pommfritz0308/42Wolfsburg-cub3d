/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:49:00 by fbohling          #+#    #+#             */
/*   Updated: 2023/11/13 15:32:52 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[5000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4999)
		return (NULL);
	stash[fd] = ft_read(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = make_line(stash[fd]);
	if (!line || !line[0])
		return (free(line), free(stash[fd]), NULL);
	stash[fd] = get_remainder(stash[fd]);
	if (!stash[fd])
		return (NULL);
	return (line);
}

char	*ft_read(char *stash, int fd)
{
	char	*buff;
	int		readret;

	readret = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((!ft_strchr_gnl((char *)stash, '\n') && readret != 0))
	{
		readret = (read(fd, buff, BUFFER_SIZE));
		if (readret == -1)
			return (free(buff), free(stash), NULL);
		buff[readret] = '\0';
		stash = ft_strjoin_gnl(stash, buff);
		if (readret == 0 && ft_strlen_gnl(stash) == 0)
			return (free(buff), free(stash), NULL);
	}
	return (free(buff), stash);
}

char	*make_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line = malloc((i + 2) * sizeof(char));
			if (!line)
				return (NULL);
			ft_memcpy_gnl(line, stash, i + 1);
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy_gnl(line, stash, i);
	line[i] = '\0';
	return (line);
}

char	*get_remainder(char *stash)
{
	int		start;
	int		i;
	int		remainder;
	char	*temp;

	i = 0;
	start = 0;
	while (stash[start] != '\n' && stash[start])
		start++;
	temp = malloc((ft_strlen_gnl(stash) - start + 1) * sizeof(char));
	remainder = ft_strlen_gnl(stash) - start - 1;
	if (temp == NULL)
		return (NULL);
	start++;
	while (i < remainder)
	{
		temp[i] = stash[start + i];
		i++;
	}
	temp[i] = '\0';
	return (free(stash), temp);
}
