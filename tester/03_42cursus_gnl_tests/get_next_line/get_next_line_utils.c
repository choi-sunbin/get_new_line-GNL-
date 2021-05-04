/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:01:55 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/04 01:24:15 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *dest, int check)
{
	while (1)
	{
		if (*dest == (char)check)
			return ((char *)dest);
		if (*dest == 0)
			return (0);
		dest++;
	}
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*memory;
	size_t	loop;

	len = ft_strlen(s);
	memory = (char*)malloc(len + 1);
	if (memory == 0)
		return (0);
	loop = 0;
	while (loop < len + 1)
		memory[loop++] = 0;
	ft_strlcat(memory, s, len + 1);
	memory[len] = 0;
	return (memory);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	loop;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	loop = 0;
	if (dest_len > size - 1 || size == 0)
		return (size + src_len);
	if (dest_len < size - 1)
	{
		while (src[loop] != 0 && dest_len + loop < size - 1)
		{
			dest[dest_len + loop] = src[loop];
			loop++;
		}
	}
	dest[dest_len + loop] = 0;
	return (dest_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	loop;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1_len = s1 ? ft_strlen(s1) : 0;
	s2_len = s2 ? ft_strlen(s2) : 0;
	str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == 0)
		return (0);
	loop = 0;
	while (loop < s1_len + s2_len + 1)
		str[loop++] = 0;
	ft_strlcat(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	return (str);
}
