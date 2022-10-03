#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("donquijote.txt", O_RDONLY);
	int i = 0;
	while (i < 5)
	{
		if(fd == -1)
		{
			printf("error al abrir el archivo \n");
		}
		else
		{
			printf("%s",get_next_line(fd));
		}
		i++;
	}
	close (fd);
return (0);
}
