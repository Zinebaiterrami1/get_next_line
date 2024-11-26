#include "get_next_line.h"

// int	main(void)
// {
// 	int fd = open("file1.txt", O_RDWR, 7777);
// 	int r = 1;
// 	char *buffer;
// 	static char *result;
// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	r = read(fd, buffer, BUFFER_SIZE);
// 	if (fd == -1)
// 		printf("error opening file!!!!!!!!!!!!!!!!!!!!!!");
// 	while (!ft_strchr(buffer, '\n') && r)
// 	{
// 		buffer[r] = '\0';
// 		result = ft_strjoin(result, buffer);
// 		r = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	buffer[r] = '\0';
// 	result = ft_strjoin(result, buffer);
// 	printf("readed : %s\n", result);
// }

int main()
{
    int fd = open("file1.txt", O_RDWR, 7777);
	ssize_t r = 1;
	char *buffer;
	static char *result;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, buffer, BUFFER_SIZE);
	if (fd == -1)
		printf("error opening file!!!!!!!!!!!!!!!!!!!!!!");
    if(r == -1){
        printf("error while reading from the file !!!!!!!!");
    }
	while (r > 0)
	{
        buffer[r] = '\0';
        if(!result)
            result = ft_strdup(buffer);
        else
            result = ft_strjoin(result, buffer);
        if(ft_strchr(buffer, '\n'))
            break; 
        r = read(fd, buffer, BUFFER_SIZE);
	}
	printf("readed : %s", result);
    free(buffer);
    free(result);
}