#!/usr/bin/env python3
import ctypes, ctypes.util, os, pathlib, sys

SYS_PERF_EVENT_OPEN = 298
PERF_TYPE_TRACEPOINT = 1
PERF_EVENT_IOC_SET_BPF = 0x40042408
PERF_EVENT_IOC_ENABLE = 0x2400

class PerfEventAttr(ctypes.Structure):
    _fields_ = [
        ('type', ctypes.c_uint32),
        ('size', ctypes.c_uint32),
        ('config', ctypes.c_uint64),
        ('sample_period_or_freq', ctypes.c_uint64),
        ('sample_type', ctypes.c_uint64),
        ('read_format', ctypes.c_uint64),
        ('flags', ctypes.c_uint64),
        ('wakeup_events_or_watermark', ctypes.c_uint32),
        ('bp_type', ctypes.c_uint32),
        ('bp_addr_or_kprobe_func', ctypes.c_uint64),
        ('bp_len_or_kprobe_addr', ctypes.c_uint64),
        ('branch_sample_type', ctypes.c_uint64),
        ('sample_regs_user', ctypes.c_uint64),
        ('sample_stack_user', ctypes.c_uint32),
        ('clockid', ctypes.c_int32),
        ('sample_regs_intr', ctypes.c_uint64),
        ('aux_watermark', ctypes.c_uint32),
        ('sample_max_stack', ctypes.c_uint16),
        ('reserved_2', ctypes.c_uint16),
        ('aux_sample_size', ctypes.c_uint32),
        ('reserved_3', ctypes.c_uint32),
        ('sig_data', ctypes.c_uint64),
    ]

if __name__ == '__main__':
    lib = ctypes.CDLL(ctypes.util.find_library('c') or 'libc.so.6', use_errno=True)
    lib.syscall.restype = ctypes.c_long
    lib.ioctl.restype = ctypes.c_int
    lib.ioctl.argtypes = [ctypes.c_int, ctypes.c_ulong, ctypes.c_long]

    all_ok = True
    for cat, evt in [('task', 'task_newtask'), ('sched', 'sched_process_exit'), ('oom', 'mark_victim')]:
        found = False
        for base in ['/sys/kernel/debug/tracing/events', '/sys/kernel/tracing/events']:
            p = pathlib.Path(f'{base}/{cat}/{evt}/id')
            try:
                exists = p.exists()
                if exists:
                    tp_id_text = p.read_text().strip()
            except PermissionError:
                exists = False
            if exists:
                tp_id = int(tp_id_text)
                print(f'{cat}/{evt} id={tp_id}', end=' ')

                attr = PerfEventAttr()
                ctypes.memset(ctypes.byref(attr), 0, ctypes.sizeof(attr))
                attr.type = PERF_TYPE_TRACEPOINT
                attr.size = ctypes.sizeof(attr)
                attr.config = tp_id
                attr.sample_period_or_freq = 1
                attr.wakeup_events_or_watermark = 1

                pfd = lib.syscall(SYS_PERF_EVENT_OPEN, ctypes.byref(attr), ctypes.c_int(-1), ctypes.c_int(0), ctypes.c_int(-1), ctypes.c_ulong(0))
                if pfd < 0:
                    err = ctypes.get_errno()
                    print(f'FAIL: {os.strerror(err)} (errno={err})')
                    all_ok = False
                else:
                    print(f'OK (fd={pfd})')
                    os.close(pfd)
                found = True
                break
        if not found:
            print(f'{cat}/{evt}: NOT FOUND')
            all_ok = False

    sys.exit(0 if all_ok else 1)
