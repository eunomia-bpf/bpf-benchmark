#include "../../kprog/libnativeloader/src/native_loader_fd_scan.hpp"

#include <cassert>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

static void write_byte(int fd, char byte)
{
    assert(ftruncate(fd, 0) == 0);
    assert(pwrite(fd, &byte, 1, 0) == 1);
}

static char read_byte(int fd)
{
    char byte = 0;
    assert(pread(fd, &byte, 1, 0) == 1);
    return byte;
}

int main()
{
    char original_path[] = "/tmp/native-loader-fd-original-XXXXXX";
    char replacement_path[] = "/tmp/native-loader-fd-replacement-XXXXXX";
    const int raw_fd = mkstemp(original_path);
    const int replacement_fd = mkstemp(replacement_path);
    assert(raw_fd >= 0);
    assert(replacement_fd >= 0);
    unlink(original_path);
    unlink(replacement_path);
    write_byte(raw_fd, 'A');
    write_byte(replacement_fd, 'B');

    const int pinned_fd = pin_open_process_fd_for_scan(raw_fd);
    assert(pinned_fd >= 0);
    assert((fcntl(pinned_fd, F_GETFD) & FD_CLOEXEC) != 0);

    assert(close(raw_fd) == 0);
    assert(dup2(replacement_fd, raw_fd) == raw_fd);
    assert(read_byte(raw_fd) == 'B');
    assert(read_byte(pinned_fd) == 'A');

    assert(close(raw_fd) == 0);
    errno = 0;
    assert(pin_open_process_fd_for_scan(raw_fd) == -1);
    assert(open_process_fd_went_stale(errno));
    assert(open_process_fd_went_stale(ENOENT));
    assert(!open_process_fd_went_stale(EINVAL));

    assert(close(pinned_fd) == 0);
    assert(close(replacement_fd) == 0);
    std::puts("native loader fd scan: PASS");
    return 0;
}
