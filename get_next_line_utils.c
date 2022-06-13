/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeurico- <jeurico-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:11:49 by jeurico-          #+#    #+#             */
/*   Updated: 2022/06/13 19:55:42 by jeurico-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count] != '\0')
	{
		count ++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			count;
	unsigned char	ch;

	count = 0;
	ch = c;
	while (s[count])
	{
		if (s[count] == ch)
		{
			return ((char *)(&s[count]));
		}
		count++;
	}
	if (s[count] == ch)
	{
		return ((char *)(&s[count]));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string_new;
	int		string_len;
	int		count;
	int		count2;

	string_len = ft_strlen(s1) + ft_strlen(s2);
	string_new = (char *) malloc((string_len + 1) * sizeof(char));
	if (!string_new)
		return (0);
	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		string_new[count] = s1[count];
		count++;
	}
	while (s2[count2] != '\0')
	{
		string_new[count] = s2[count2];
		count++;
		count2++;
	}
	string_new[count] = '\0';
	return (string_new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;
	char	*pntr_dest;
	char	*pntr_src;

	count = 0;
	pntr_dest = dest;
	pntr_src = (char *)src;
	while (count < n)
	{
		pntr_dest[count] = pntr_src[count];
		count ++;
	}
	return (pntr_dest);
}
