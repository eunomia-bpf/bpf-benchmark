"""Low-level BPF program attachment helpers using perf_event_open + ioctl.

Supports tracepoint, kprobe, and cgroup_sysctl attachment without requiring
bpftool autoattach (which fails on partial-attach objects).
"""
from __future__ import annotations

import ctypes
import ctypes.util
import os
import struct
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator


# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

# perf_event_open syscall number (x86_64)
import platform as _platform

_MACHINE = _platform.machine()
if _MACHINE in ("x86_64", "amd64"):
    SYS_PERF_EVENT_OPEN = 298
elif _MACHINE == "aarch64":
    SYS_PERF_EVENT_OPEN = 241
else:
    SYS_PERF_EVENT_OPEN = 298  # fallback; may need adjustment

if _MACHINE in ("x86_64", "amd64"):
    SYS_BPF = 321
elif _MACHINE == "aarch64":
    SYS_BPF = 280
else:
    SYS_BPF = 321  # fallback

# perf_event_attr.type
PERF_TYPE_HARDWARE = 0
PERF_TYPE_SOFTWARE = 1
PERF_TYPE_TRACEPOINT = 2

# perf_event_attr.config for kprobe/uprobe via perf PMU
PERF_COUNT_SW_BPF_OUTPUT = 10

# ioctl commands
PERF_EVENT_IOC_ENABLE = 0x2400
PERF_EVENT_IOC_DISABLE = 0x2401
PERF_EVENT_IOC_SET_BPF = 0x40042408

# BPF commands
BPF_PROG_ATTACH = 8
BPF_LINK_CREATE = 28

# BPF attach types
BPF_CGROUP_SYSCTL = 18

# perf_event_attr size (v5 structure, 120 bytes is typical)
PERF_ATTR_SIZE = 120


class PerfEventAttr(ctypes.Structure):
    """Minimal perf_event_attr for tracepoint attachment."""
    _fields_ = [
        ("type", ctypes.c_uint32),
        ("size", ctypes.c_uint32),
        ("config", ctypes.c_uint64),
        ("sample_period_or_freq", ctypes.c_uint64),
        ("sample_type", ctypes.c_uint64),
        ("read_format", ctypes.c_uint64),
        ("flags", ctypes.c_uint64),
        ("wakeup_events_or_watermark", ctypes.c_uint32),
        ("bp_type", ctypes.c_uint32),
        ("bp_addr_or_kprobe_func_or_uprobe_path_or_config1", ctypes.c_uint64),
        ("bp_len_or_kprobe_addr_or_probe_offset_or_config2", ctypes.c_uint64),
        ("branch_sample_type", ctypes.c_uint64),
        ("sample_regs_user", ctypes.c_uint64),
        ("sample_stack_user", ctypes.c_uint32),
        ("clockid", ctypes.c_int32),
        ("sample_regs_intr", ctypes.c_uint64),
        ("aux_watermark", ctypes.c_uint32),
        ("sample_max_stack", ctypes.c_uint16),
        ("__reserved_2", ctypes.c_uint16),
        ("aux_sample_size", ctypes.c_uint32),
        ("__reserved_3", ctypes.c_uint32),
        ("sig_data", ctypes.c_uint64),
    ]


def _libc() -> ctypes.CDLL:
    path = ctypes.util.find_library("c") or "libc.so.6"
    lib = ctypes.CDLL(path, use_errno=True)
    lib.ioctl.restype = ctypes.c_int
    lib.ioctl.argtypes = [ctypes.c_int, ctypes.c_ulong, ctypes.c_long]
    lib.syscall.restype = ctypes.c_long
    return lib


_LIBC = None


def libc() -> ctypes.CDLL:
    global _LIBC
    if _LIBC is None:
        _LIBC = _libc()
    return _LIBC


# ---------------------------------------------------------------------------
# Tracepoint attachment
# ---------------------------------------------------------------------------

def tracepoint_id(category: str, event: str) -> int:
    """Read the tracepoint ID from debugfs/tracefs."""
    candidates = [
        Path(f"/sys/kernel/debug/tracing/events/{category}/{event}/id"),
        Path(f"/sys/kernel/tracing/events/{category}/{event}/id"),
    ]
    for path in candidates:
        if path.exists():
            return int(path.read_text().strip())
    raise RuntimeError(
        f"tracepoint {category}/{event} not found in debugfs/tracefs. "
        f"Tried: {', '.join(str(p) for p in candidates)}"
    )


def attach_tracepoint(prog_fd: int, category: str, event: str) -> int:
    """Attach a BPF program to a tracepoint via perf_event_open + ioctl.

    Returns the perf_event fd (caller must close it to detach).
    """
    tp_id = tracepoint_id(category, event)

    attr = PerfEventAttr()
    ctypes.memset(ctypes.byref(attr), 0, ctypes.sizeof(attr))
    attr.type = PERF_TYPE_TRACEPOINT
    attr.size = ctypes.sizeof(attr)
    attr.config = tp_id
    attr.sample_period_or_freq = 1
    attr.wakeup_events_or_watermark = 1

    pfd = libc().syscall(
        SYS_PERF_EVENT_OPEN,
        ctypes.byref(attr),
        ctypes.c_int(-1),   # pid = -1 (all processes)
        ctypes.c_int(0),    # cpu = 0
        ctypes.c_int(-1),   # group_fd
        ctypes.c_ulong(0),  # flags
    )
    if pfd < 0:
        err = ctypes.get_errno()
        raise RuntimeError(
            f"perf_event_open for tracepoint {category}/{event} (id={tp_id}) "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    rc = libc().ioctl(pfd, PERF_EVENT_IOC_SET_BPF, prog_fd)
    if rc < 0:
        err = ctypes.get_errno()
        os.close(pfd)
        raise RuntimeError(
            f"ioctl(SET_BPF) for tracepoint {category}/{event} "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    rc = libc().ioctl(pfd, PERF_EVENT_IOC_ENABLE, 0)
    if rc < 0:
        err = ctypes.get_errno()
        os.close(pfd)
        raise RuntimeError(
            f"ioctl(ENABLE) for tracepoint {category}/{event} "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    return pfd


# ---------------------------------------------------------------------------
# Kprobe attachment
# ---------------------------------------------------------------------------

def _kprobe_pmu_type() -> int:
    """Read the kprobe PMU type from sysfs."""
    path = Path("/sys/bus/event_source/devices/kprobe/type")
    if not path.exists():
        raise RuntimeError("kprobe PMU not available at /sys/bus/event_source/devices/kprobe/type")
    return int(path.read_text().strip())


def attach_kprobe(prog_fd: int, func_name: str, *, is_return: bool = False) -> int:
    """Attach a BPF program to a kprobe via perf_event_open + ioctl.

    Returns the perf_event fd (caller must close it to detach).
    """
    pmu_type = _kprobe_pmu_type()

    # Encode function name as a null-terminated C string
    func_bytes = func_name.encode("utf-8") + b"\0"
    func_buf = ctypes.create_string_buffer(func_bytes)
    func_ptr = ctypes.cast(func_buf, ctypes.c_void_p).value

    attr = PerfEventAttr()
    ctypes.memset(ctypes.byref(attr), 0, ctypes.sizeof(attr))
    attr.type = pmu_type
    attr.size = ctypes.sizeof(attr)
    # config: bit 0 = is_return
    attr.config = 1 if is_return else 0
    attr.sample_period_or_freq = 1
    attr.wakeup_events_or_watermark = 1
    # config1 = pointer to function name string
    attr.bp_addr_or_kprobe_func_or_uprobe_path_or_config1 = func_ptr

    pfd = libc().syscall(
        SYS_PERF_EVENT_OPEN,
        ctypes.byref(attr),
        ctypes.c_int(-1),   # pid = -1
        ctypes.c_int(0),    # cpu = 0
        ctypes.c_int(-1),   # group_fd
        ctypes.c_ulong(0),  # flags
    )
    if pfd < 0:
        err = ctypes.get_errno()
        raise RuntimeError(
            f"perf_event_open for kprobe {func_name} "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    rc = libc().ioctl(pfd, PERF_EVENT_IOC_SET_BPF, prog_fd)
    if rc < 0:
        err = ctypes.get_errno()
        os.close(pfd)
        raise RuntimeError(
            f"ioctl(SET_BPF) for kprobe {func_name} "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    rc = libc().ioctl(pfd, PERF_EVENT_IOC_ENABLE, 0)
    if rc < 0:
        err = ctypes.get_errno()
        os.close(pfd)
        raise RuntimeError(
            f"ioctl(ENABLE) for kprobe {func_name} "
            f"failed: {os.strerror(err)} (errno={err})"
        )

    return pfd


# ---------------------------------------------------------------------------
# Cgroup sysctl attachment
# ---------------------------------------------------------------------------

def attach_cgroup_sysctl(prog_fd: int, cgroup_path: str = "/sys/fs/cgroup") -> int:
    """Attach a BPF cgroup/sysctl program to a cgroup via BPF_PROG_ATTACH.

    Returns the cgroup fd used for attachment. The caller should detach
    (BPF_PROG_DETACH) and close the fd when done.
    """
    cgroup_fd = os.open(cgroup_path, os.O_RDONLY | os.O_CLOEXEC)
    try:
        # BPF_PROG_ATTACH: cmd=8
        # attr layout: target_fd(u32), attach_bpf_fd(u32), attach_type(u32), attach_flags(u32)
        # Total bpf_attr is 120+ bytes; we use a bytes buffer
        attr_size = 120
        attr_buf = bytearray(attr_size)
        struct.pack_into("III", attr_buf, 0, cgroup_fd, prog_fd, BPF_CGROUP_SYSCTL)

        attr_array = (ctypes.c_ubyte * attr_size).from_buffer(attr_buf)
        rc = libc().syscall(
            SYS_BPF,
            ctypes.c_int(BPF_PROG_ATTACH),
            ctypes.byref(attr_array),
            ctypes.c_uint32(attr_size),
        )
        if rc < 0:
            err = ctypes.get_errno()
            raise RuntimeError(
                f"BPF_PROG_ATTACH(cgroup_sysctl) to {cgroup_path} "
                f"failed: {os.strerror(err)} (errno={err})"
            )
        return cgroup_fd
    except Exception:
        os.close(cgroup_fd)
        raise


def detach_cgroup_sysctl(cgroup_fd: int, prog_fd: int) -> None:
    """Detach a BPF cgroup/sysctl program."""
    attr_size = 120
    attr_buf = bytearray(attr_size)
    # BPF_PROG_DETACH: cmd=9
    struct.pack_into("III", attr_buf, 0, cgroup_fd, prog_fd, BPF_CGROUP_SYSCTL)
    attr_array = (ctypes.c_ubyte * attr_size).from_buffer(attr_buf)
    libc().syscall(
        SYS_BPF,
        ctypes.c_int(9),  # BPF_PROG_DETACH
        ctypes.byref(attr_array),
        ctypes.c_uint32(attr_size),
    )


# ---------------------------------------------------------------------------
# Section name parsing
# ---------------------------------------------------------------------------

# Known non-standard section name mappings for specific projects.
# Maps (section_name) -> (category, event) for tracepoints that use
# abbreviated section names (e.g. Tetragon uses "tracepoint/sys_execve"
# instead of "tracepoint/syscalls/sys_enter_execve").
SECTION_TRACEPOINT_ALIASES: dict[str, tuple[str, str]] = {
    "tracepoint/sys_execve": ("syscalls", "sys_enter_execve"),
    "tracepoint/sys_execveat": ("syscalls", "sys_enter_execveat"),
}


def parse_section_attach_info(section_name: str) -> dict[str, str]:
    """Parse a BPF section name to determine attachment type and target.

    Returns a dict with keys:
      - attach_method: "tracepoint", "kprobe", "kretprobe", "uprobe", "cgroup_sysctl", "unknown"
      - category: tracepoint category (e.g., "sched") or empty
      - event: tracepoint event name or kprobe function name
    """
    # Check aliases first
    if section_name in SECTION_TRACEPOINT_ALIASES:
        category, event = SECTION_TRACEPOINT_ALIASES[section_name]
        return {
            "attach_method": "tracepoint",
            "category": category,
            "event": event,
        }

    parts = section_name.split("/")

    if parts[0] == "tracepoint" and len(parts) >= 3:
        return {
            "attach_method": "tracepoint",
            "category": parts[1],
            "event": parts[2],
        }
    if parts[0] == "tracepoint" and len(parts) == 2:
        # e.g., tracepoint/sys_execve — try alias lookup (already done above),
        # otherwise return with empty category (caller should skip)
        return {
            "attach_method": "tracepoint",
            "category": "",
            "event": parts[1],
        }
    if parts[0] == "tracepoint" and len(parts) == 1:
        # Bare "tracepoint" section (e.g. Tetragon helper programs).
        # Attach target is unknown; caller should skip.
        return {
            "attach_method": "tracepoint_bare",
            "category": "",
            "event": "",
        }
    if parts[0] == "kprobe" and len(parts) >= 2:
        return {
            "attach_method": "kprobe",
            "category": "",
            "event": parts[1],
        }
    if parts[0] == "kretprobe" and len(parts) >= 2:
        return {
            "attach_method": "kretprobe",
            "category": "",
            "event": parts[1],
        }
    if parts[0] in ("uprobe", "uretprobe"):
        return {
            "attach_method": "uprobe",
            "category": "",
            "event": "/".join(parts[1:]) if len(parts) > 1 else "",
        }
    if parts[0] in ("cgroup/sysctl", "cgroup") and "sysctl" in section_name:
        return {
            "attach_method": "cgroup_sysctl",
            "category": "",
            "event": "",
        }

    return {
        "attach_method": "unknown",
        "category": "",
        "event": "",
    }


def bpf_obj_get(pin_path: str) -> int:
    """Open a pinned BPF object (program or map) and return its fd.

    Uses the BPF_OBJ_GET syscall command.
    """
    BPF_OBJ_GET = 7
    # bpf_attr for BPF_OBJ_GET: pathname(u64), bpf_fd(u32), file_flags(u32)
    path_bytes = pin_path.encode("utf-8") + b"\0"
    path_buf = ctypes.create_string_buffer(path_bytes)
    path_ptr = ctypes.cast(path_buf, ctypes.c_void_p).value

    attr_size = 120
    attr_buf = bytearray(attr_size)
    # pathname is at offset 0, stored as u64 pointer
    struct.pack_into("Q", attr_buf, 0, path_ptr)

    attr_array = (ctypes.c_ubyte * attr_size).from_buffer(attr_buf)
    fd = libc().syscall(
        SYS_BPF,
        ctypes.c_int(BPF_OBJ_GET),
        ctypes.byref(attr_array),
        ctypes.c_uint32(attr_size),
    )
    if fd < 0:
        err = ctypes.get_errno()
        raise RuntimeError(
            f"BPF_OBJ_GET({pin_path}) failed: {os.strerror(err)} (errno={err})"
        )
    return int(fd)


@contextmanager
def managed_attachments(attachments: list[int]) -> Iterator[list[int]]:
    """Context manager that closes all perf_event fds on exit."""
    try:
        yield attachments
    finally:
        for fd in attachments:
            try:
                os.close(fd)
            except OSError:
                pass


__all__ = [
    "attach_cgroup_sysctl",
    "attach_kprobe",
    "attach_tracepoint",
    "bpf_obj_get",
    "detach_cgroup_sysctl",
    "managed_attachments",
    "parse_section_attach_info",
    "tracepoint_id",
]
