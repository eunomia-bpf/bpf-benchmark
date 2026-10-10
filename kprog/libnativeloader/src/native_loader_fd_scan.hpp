#ifndef BPFREJIT_NATIVE_LOADER_FD_SCAN_HPP
#define BPFREJIT_NATIVE_LOADER_FD_SCAN_HPP

#include <cerrno>
#include <fcntl.h>

inline int pin_open_process_fd_for_scan(int fd)
{
    return fcntl(fd, F_DUPFD_CLOEXEC, 0);
}

inline bool open_process_fd_went_stale(int error)
{
    return error == EBADF || error == ENOENT;
}

#endif
