/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:54:19 by zait-err          #+#    #+#             */
/*   Updated: 2024/12/01 18:24:58 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*lines;
	static char *stash[1024];
	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	stash[fd] = _fill_line_buffer(fd, stash[fd]);
	if(!stash[fd])
		return(NULL);
	lines = _set_line(stash[fd]);
	stash[fd] = _helper_function(stash[fd]);
	return(lines);
}

char	*_fill_line_buffer(int fd, char *str)
{
	ssize_t	r;
	char *buffer;
	
	r = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return(NULL);
	if (fd == -1)
		return (NULL);
	while (!ft_strchr(str, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str); 
}

char *_helper_function(char *line)
{
	ssize_t i;
	char *left_c;
	
	i = 0;
    while (line[i] && line[i] != '\n')
		i++;  
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if(line[i] == '\n')
		i++;                                              
	left_c = ft_substr(line, i, ft_strlen(line) - i);
	if(!left_c)
	{
		free(line);
		return(NULL);
	}
	free(line);
	return(left_c);
}

char *_set_line(char *line_buffer)
{
	ssize_t i;
	char *line;
	ssize_t j;

	j = 0;
	i = 0;
	if (!ft_strlen(line_buffer))
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;

	if (line_buffer[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if(!line)
		return(NULL);
	while (j <= i && line_buffer[j])
	{
		line[j] = line_buffer[j];
		j ++;
	}
	line[j] = '\0';
	return(line);
}
