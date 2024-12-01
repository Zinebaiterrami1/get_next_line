#include "get_next_line.h"

int main()
{
	int fd = open("file1.txt", O_RDWR, 7777);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
	char *result;
    while (1)
    {
		result = get_next_line(fd);
		printf("read : (%s)\n", result);
		if (result == NULL)
		{
			printf("breaking from loop\n");
			break ;
		} 
	}
	free(result);
}

/*bonus part*/

// int main()
// {
// 	int fd = open("file1.txt", O_RDWR, 7777);
// 	int fd1 = open("file2.txt",O_RDWR, 7777);
// 	int fd2 = open("file3.txt",O_RDWR, 7777);
	
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// }

// int main()
// {
// 	int fd = open("file1.txt", O_RDWR, 7777);
// //     if (fd == -1)
// //     {
// //         printf("Error opening file");
// //         return (1);
// //     }
// 	char *result;
// //     // while (1)
// //     // {
// // 	// 	result = get_next_line(fd);
// // 	// 	printf("read : (%s)\n", result);
// // 	// 	if (result == NULL)
// // 	// 	{
// // 	// 		printf("breaking from loop\n");
// // 	// 		break ;
// // 	// 	} 
// // 	// 	free(result);
// // 	// }
// 	while ((result = get_next_line(fd)) != NULL)
// 	{
// 		printf("readed : %s", result);
// 		free(result);
// 	}
// }


// int main(int ac, char **av)
// {
//     if (ac < 2)
//     {
//         printf("Usage: %s <filename>\n", av[0]);
//         return (1);
//     }

//     int fd = open(av[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("read: %s", line); // `line` already contains '\n' if present
//         free(line);
//     }

//     if (close(fd) == -1)
//     {
//         perror("Error closing file");
//         return (1);
//     }

//     return (0);
// }

/*-----------------------------*/

//  int main(int ac, char **av)
//  {
//     char *file;
//     file = strdup(av[1]);
//     int fd = open(file, O_RDONLY);
//     free(file);
//     char *line;
//     line = get_next_line(6000);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(6000);
//     }
        
//  }