/* Insert every sibling kinsn before the native binding regression runs as PID1. */
#define _GNU_SOURCE
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(void)
{
    DIR *directory = opendir("/kinsn");
    if (!directory) { perror("open kinsn bundle"); return 1; }
    unsigned count = 0;
    errno = 0;
    struct dirent *entry;
    while ((entry = readdir(directory))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") ||
            !strcmp(entry->d_name, "bpf_arm64_native_lab.ko")) continue;
        char path[512];
        int length = snprintf(path, sizeof(path), "/kinsn/%s", entry->d_name);
        if (length < 0 || length >= (int)sizeof(path)) { fputs("module path too long\n",stderr); return 1; }
        int fd = open(path, O_RDONLY);
        if (fd < 0 || syscall(SYS_finit_module, fd, "", 0)) { perror(path); return 1; }
        if (close(fd)) { perror("close sibling module"); return 1; }
        printf("paired sibling module inserted: %s\n",entry->d_name);
        count++;
        errno = 0;
    }
    if (errno || closedir(directory)) { perror("read/close kinsn bundle"); return 1; }
    if (count != 10) { fprintf(stderr,"expected10 sibling modules, got%u\n",count); return 1; }
    fflush(stdout);
    execl("/test-binding-kernel", "test-binding-kernel", (char *)NULL);
    perror("exec native binding regression");
    return 1;
}
