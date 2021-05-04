/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:44:59 by nvan-der          #+#    #+#             */
/*   Updated: 2021/05/03 23:49:13 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_substr(char *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	while (j < i)
	{
		ret[j] = s[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	str_size;

	str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * str_size);
	if (result == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	result = ft_cpy_cat(s1, s2, result);
	free(s1);
	free(s2);
	return (result);
}

char		*ft_strdup(char *s)
{
	int		i;
	char	*ret;

	i = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_cpy_cat(char *ori, char *app, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ori[i] != '\0')
	{
		ret[i] = ori[i];
		i++;
	}
	while (app[j] != '\0')
	{
		ret[i] = app[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}