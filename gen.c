#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

void				write_to_file(int fd, char *line)
{
	int			i = 0;

	while (line[i])
	{
		if ((write(fd, &line[i], 1)) < 0)
		{
			printf("Error writing to file\n");
			exit(0);
		}
		i++;
	}
}


int				main(void)
{
	int			i = 1;
	char		index[10];
	int			total = 101;
	int			fd;

	char		*line1 = (char *)malloc(200 * sizeof(char));
	char		line1_1[] = "call gradlew.bat run --args=\"--size=60,60 --mask ..\\mask\\'mask (\0";
	char		line1_2[] = ").png'\"\n\0";

	char		*line2 = (char *)malloc(200 * sizeof(char));
	char		line2_1[] = "call rename solution.svg solution\0";
	char		line2_2[] = ".svg\n\0";

	char		*line3 = (char *)malloc(200 * sizeof(char));
	char		line3_1[] = "call move solution\0";
	char		line3_2[] = ".svg ..\\SOLUTIONS\\\n\0";

	char		*line4 = (char *)malloc(200 * sizeof(char));
	char		line4_1[] = "call rename maze.svg maze\0";
	char		line4_2[] = ".svg\n\0";

	char		*line5 = (char *)malloc(200 * sizeof(char));
	char		line5_1[] = "call move maze\0";
	char		line5_2[] = ".svg ..\\MAZES\\\n\0";

	char		*line6 = (char *)malloc(200 * sizeof(char));
	char		line6_1[] = "echo \"\0";
	char		line6_2[] = " GENERATED\"\n\0";


	if ((fd = open("generate_bulk.bat", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0)
		printf("Couldn't create a file\n");

	write_to_file(fd, "cd generator\\\n\n\0");

	while (i != total)
	{
		bzero(&index, 10);
		bzero(line1, 200);
		bzero(line2, 200);
		bzero(line3, 200);
		bzero(line4, 200);
		bzero(line5, 200);
		bzero(line6, 200);
		sprintf(index, "%d", i);

		strcpy(line1, line1_1);
		strcat(line1, index);
		strcat(line1, line1_2);
		write_to_file(fd, line1);

		strcpy(line2, line2_1);
		strcat(line2, index);
		strcat(line2, line2_2);
		write_to_file(fd, line2);

		strcpy(line3, line3_1);
		strcat(line3, index);
		strcat(line3, line3_2);
		write_to_file(fd, line3);

		strcpy(line4, line4_1);
		strcat(line4, index);
		strcat(line4, line4_2);
		write_to_file(fd, line4);

		strcpy(line5, line5_1);
		strcat(line5, index);
		strcat(line5, line5_2);
		write_to_file(fd, line5);

		strcpy(line6, line6_1);
		strcat(line6, index);
		strcat(line6, line6_2);
		write_to_file(fd, line6);

		write_to_file(fd, "\n\0");

		i++;
	}
	return 0;
}
