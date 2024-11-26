/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:39 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/26 13:57:25 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    if(!s)
        return(0);
    while (s[i])
    {
        i++;
    }
    return (i);
}
char    *ft_strdup(const char *s)
{
    size_t len_s;
    char *array;
    size_t i;

    i = 0;
    len_s = ft_strlen(s);
    array = malloc(sizeof(char) * (len_s + 1));
    if (!array)
        return(NULL);
    while (s[i])
    {
        array[i] = s[i];
        i++;
    }
    array[i] = '\0';
    return(array);
}

char	*ft_strchr(const char *str, int c)
{
	if(!str)
		return(NULL);
    while (*str != '\0')
	{
		if(*str == (char)c)
			return((char*)str);
		str++;
	}
	if(*str == (char)c)
		return((char*)str);
	return(NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
    if (!s2)
        return (0);
    if (!s1)
	{
        return (ft_strdup(s2));
	}
	new_str = (char *)malloc((sizeof(char) * (ft_strlen((char *)s1)
					+ ft_strlen((char *)s2) + 1)));
	if(!new_str)
		return(NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return(new_str);
}
