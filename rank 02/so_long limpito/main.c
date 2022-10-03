#include "so_long.h"

int main()
{
    char    *line;
    int     fd;

    fd = open("map.ber", O_RDWR);
    line = get_next_line(fd);
    printf("Line 1: %s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("Line 2: %s\n", line);
    free(line);
    close(fd);
    return (0);
}