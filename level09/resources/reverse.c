#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    char buff[100];
    int i = 0;
    int fd = open("./token", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    int read_size = read(fd, buff, 100); 
    if (read_size == -1) {
        perror("read");
        return 1;
    }
    buff[read_size] = '\0';
    while (buff[i]) {
        buff[i] -= i;
        i++;
    }
    printf("%s\n", buff);
    close(fd);
    return 0;
}
