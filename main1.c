#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("teste.txt", O_RDONLY);
    close(fd); // Fechamos logo!
    char *line = get_next_line(fd);
    printf("Resultado com FD fechado: %s\n", line);
}
