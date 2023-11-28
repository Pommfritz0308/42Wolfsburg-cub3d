/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:53:43 by fbohling          #+#    #+#             */
/*   Updated: 2023/11/28 10:49:20 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_file_format(char *format, char *str)
{
	size_t	a;
	size_t	b;

	if (!*format)
		return (1);
	a = ft_strlen(str);
	b = ft_strlen(format);
	if (b > a)
		return (1);
	while (a > 0 && b > 0)
	{
		b--;
		a--;
		if (format[b] == str[a])
		{
			if (!b)
				return (0);
		}
		else
			break ;
	}
	return (1);
}
