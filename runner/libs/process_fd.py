from __future__ import annotations

import ctypes
import os


SYS_PIDFD_GETFD = 438


def dup_fd_from_process(pid: int, target_fd: int) -> int:
    if not hasattr(os, "pidfd_open"):
        raise RuntimeError("FD duplication requires os.pidfd_open support")
    pidfd = os.pidfd_open(int(pid), 0)
    try:
        libc = ctypes.CDLL(None, use_errno=True)
        libc.syscall.restype = ctypes.c_long
        result = int(libc.syscall(SYS_PIDFD_GETFD, int(pidfd), int(target_fd), 0))
        if result < 0:
            err = ctypes.get_errno()
            raise RuntimeError(
                f"pidfd_getfd failed for pid={pid} fd={target_fd}: {os.strerror(err)} (errno={err})"
            )
        return result
    finally:
        os.close(pidfd)
