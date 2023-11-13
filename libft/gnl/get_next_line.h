/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:04:39 by fbohling          #+#    #+#             */
/*   Updated: 2023/11/13 15:31:35 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen_gnl(char *s);
void	*ft_memcpy_gnl(void *dst, void *src, size_t n);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *str, char *buff);
char	*get_next_line(int fd);
char	*ft_read(char *line, int fd);
char	*make_line(char *stash);
char	*get_remainder(char *stash);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif
