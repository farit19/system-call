#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    int src, dest;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    src = open("result.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening source file");
        return 1;
    }

    dest = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error opening destination file");
        close(src);
        return 1;
    }

    while ((bytesRead = read(src, buffer, BUFFER_SIZE)) > 0) {
        write(dest, buffer, bytesRead);
    }

    close(src);
    close(dest);

    write(1, "File copied successfully!\n", 27);
    return 0;
}
