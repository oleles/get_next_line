/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeurico- <jeurico-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:12:22 by jeurico-          #+#    #+#             */
/*   Updated: 2022/06/13 19:47:31 by jeurico-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_clear_mem(char *rest, char *buff)
{
	char	*phrase;

	phrase = ft_strjoin(rest, buff);
	free(rest);
	return (phrase);
}

static char	*ft_find_rest(char *rest)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	while ((rest[count]) && (rest[count] != '\n'))
		count++;
	if (rest[count] == '\0')
	{
		free(rest);
		return (0);
	}
	str = (char *)malloc((ft_strlen(rest) - count + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	count++;
	while (rest[count])
		str[i++] = rest[count++];
	str[i] = '\0';
	free(rest);
	return (str);
}

static char	*ft_find_line(char *rest)
{
	int		count;
	char	*str;

	count = 0;
	if (rest[count] == '\0')
		return (0);
	while ((rest[count]) && (rest[count] != '\n'))
		count++;
	str = (char *)malloc((count + 2) * sizeof(char));
	if (!str)
		return (0);
	count = 0;
	while ((rest[count]) && (rest[count] != '\n'))
	{
		str[count] = rest[count];
		count++;
	}
	if ((rest[count]) && (rest[count] == '\n'))
	{
		str[count] = '\n';
		count++;
	}
	str[count] = '\0';
	return (str);
}

static char	*ft_read(char *rest, int fd)
{
	char	*buff;
	int		words;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	words = 1;
	while ((!ft_strchr(rest, '\n')) && (words != 0))
	{
		words = read(fd, buff, BUFFER_SIZE);
		if (words == -1)
		{
			free(buff);
			if (rest)
				free(rest);
			return (0);
		}
		buff[words] = '\0';
		rest = ft_clear_mem(rest, buff);
	}
	free(buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	if (!rest)
	{
		rest = malloc(1);
		rest[0] = '\0';
	}
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	rest = ft_read(rest, fd);
	if (!rest)
	{
		free(rest);
		return (0);
	}
	str = ft_find_line(rest);
	rest = ft_find_rest(rest);
	return (str);
}
