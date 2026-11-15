"""Release an explicitly identified resource flock held by an owned launcher.

The caller must establish that the remaining compiler stage consumes only its
canonical preprocessed input and system toolchain. pidfd_getfd duplicates the
same open file description; unlocking it leaves the compiler and log pipeline
running. No process is stopped or restarted.
"""
import argparse
import ctypes
import fcntl
import json
import os
from pathlib import Path


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    proc = Path('/proc') / str(a.pid)
    record = dict(pid=a.pid, fd=a.fd, lock=str(a.lock),
                  command=proc.joinpath('cmdline').read_bytes().decode().split('\0'),
                  before=proc.joinpath('fdinfo', str(a.fd)).read_text())
    libc = ctypes.CDLL(None, use_errno=True)
    getfd = libc.pidfd_getfd
    getfd.argtypes, getfd.restype = [ctypes.c_int, ctypes.c_int, ctypes.c_uint], ctypes.c_int
    pidfd = os.pidfd_open(a.pid)
    try:
        fd = getfd(pidfd, a.fd, 0)
        if fd < 0:
            code = ctypes.get_errno()
            raise OSError(code, os.strerror(code))
        try:
            actual, expected = os.fstat(fd), a.lock.stat()
            if (actual.st_dev, actual.st_ino) != (expected.st_dev, expected.st_ino):
                raise ValueError('The supplied descriptor does not refer to the requested resource lock')
            fcntl.flock(fd, fcntl.LOCK_UN)
        finally:
            os.close(fd)
    finally:
        os.close(pidfd)
    record['after'] = proc.joinpath('fdinfo', str(a.fd)).read_text()
    (a.output / 'released.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps(record))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--pid', type=int, required=True)
    p.add_argument('--fd', type=int, required=True)
    for name in ('lock', 'output'):
        p.add_argument('--' + name, type=Path, required=True)
    main(p.parse_args())
