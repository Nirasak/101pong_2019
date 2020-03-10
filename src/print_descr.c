/*
** EPITECH PROJECT, 2019
** print_descr.c
** File description:
** print descr
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int find_size_of_file(char const *filepath)
{
    struct stat buf;
    int size;

    stat(filepath, &buf);
    size = buf.st_size;
    return (size);
}

int print_descr(void)
{
    int fd = open("read_me", O_RDONLY);
    int size = find_size_of_file("read_me");
    char *buffer = malloc(sizeof(char) * (size + 1));
    char *save_buffer = buffer;

    read(fd, buffer, size);
    write(1, buffer, size);
    free(save_buffer);
    close(fd);
    return (0);
}
