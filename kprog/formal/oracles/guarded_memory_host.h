/* Boundary regression support: the real memory access must fault, not return zero. */
#ifndef KPROG_GUARDED_MEMORY_HOST_H
#define KPROG_GUARDED_MEMORY_HOST_H
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
struct host_guarded_memory {
    void *mapping;
    size_t mapping_bytes;
    volatile unsigned char *data;
};
static struct host_guarded_memory host_guarded_memory(size_t bytes)
{
    long page=sysconf(_SC_PAGESIZE);
    if (page<=0 || bytes>(size_t)page) { fprintf(stderr,"invalid guarded arena size\n"); exit(1); }
    void *mapping=mmap(NULL,(size_t)page*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    if (mapping==MAP_FAILED) { perror("mmap guard arena"); exit(1); }
    if (mprotect((unsigned char *)mapping+page,(size_t)page,PROT_NONE)) { perror("mprotect guard arena"); exit(1); }
    return (struct host_guarded_memory){mapping,(size_t)page*2,(volatile unsigned char *)mapping+page-bytes};
}
static int host_memory_fault(void (*access)(void *),void *argument)
{
    pid_t pid=fork();
    if (pid<0) { perror("fork memory fault"); exit(1); }
    if (!pid) {
        const struct rlimit limit={0,0};
        if (setrlimit(RLIMIT_CORE,&limit)) { perror("disable child core"); _exit(2); }
        access(argument); _exit(0);
    }
    int status;
    if (waitpid(pid,&status,0)<0) { perror("wait memory fault"); exit(1); }
    return WIFSIGNALED(status) && WTERMSIG(status)==SIGSEGV;
}
static void host_guarded_memory_free(struct host_guarded_memory memory)
{
    if (munmap(memory.mapping,memory.mapping_bytes)) { perror("munmap guard arena"); exit(1); }
}
#endif
