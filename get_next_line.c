/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:18 by zait-err          #+#    #+#             */
/*   Updated: 2024/11/26 16:33:08 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*lines;
	
	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = _fill_line_buffer(fd, lines);
	return(lines);
}

char	*_fill_line_buffer(int fd, char *str)
{
    //Read data from the file (by file descriptor fd) and fill a buffer until encountering a \n or \0 character.
	ssize_t	r;
	char *buffer;
	
	r = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return(NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	if (fd == -1 || r == -1)
		return (NULL);
	while (r > 0)
	{
		buffer[r] = '\0';
		if(!str)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
		if(ft_strchr(buffer, '\n'))
            break; 
		r = read(fd, buffer, BUFFER_SIZE);
	}	
	free(buffer);
	return (str); 
}

// static char	*_set_line(char *line_buffer)
// {
// 	char	*left_c;
// 	ssize_t	i;

// 	// Logic to find newline and allocate memory for the line
// 	// Copy the line and return it
// 	return (line);
// }

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	buf[BUFFER_SIZE];
// 	ssize_t	numRead;

// 	fd = open(av[1], O_RDONLY);
// 	if (fd != -1)
// 	{
// 		numRead = read(fd, buf, BUFFER_SIZE - 1);
// 		while (numRead > 0)
// 		{
// 			buf[numRead] = '\0';
// 			printf("%s", buf);
// 			numRead = read(fd, buf, BUFFER_SIZE - 1);
// 		}
// 	}
// 	else
// 	{
// 		printf("error while opening file \n");
// 		return (-1);
// 	}
// }

char *_set_line(char *line_buffer)
{
	ssize_t i;
	char *tmp;
	char *line;
	ssize_t j;

	j = 0;
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if(!line)
		return(NULL);
	while (line_buffer)
	{
		line[j] = line_buffer[i];
		i ++;
		j ++;
	}
	line[i] = '\0';
	
}

int main()
{
	int fd = open("file1.txt", O_RDWR, 7777);
	char *result = get_next_line(fd);
	printf("readed : %s", result);
}