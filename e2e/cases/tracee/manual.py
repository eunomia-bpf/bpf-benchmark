from __future__ import annotations

import ctypes
import ctypes.util
import os
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence

from runner.libs.inventory import ProgramInventoryEntry


BPF_STATS_RUN_TIME = 0
BPF_TAG_SIZE = 8
BPF_OBJ_NAME_LEN = 16


class ManualTraceeLoadError(RuntimeError):
    pass


@dataclass(frozen=True, slots=True)
class ProgramHandle:
    name: str
    section_name: str
    prog_type_name: str
    prog_fd: int
    prog_id: int
    link_ptr: int | None = None


@dataclass(frozen=True, slots=True)
class ProgramSnapshot:
    prog_id: int
    run_cnt: int
    run_time_ns: int
    bytes_xlated: int
    bytes_jited: int
    prog_name: str


class BpfProgInfo(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_uint32),
        ("id", ctypes.c_uint32),
        ("tag", ctypes.c_ubyte * BPF_TAG_SIZE),
        ("jited_prog_len", ctypes.c_uint32),
        ("xlated_prog_len", ctypes.c_uint32),
        ("jited_prog_insns", ctypes.c_uint64),
        ("xlated_prog_insns", ctypes.c_uint64),
        ("load_time", ctypes.c_uint64),
        ("created_by_uid", ctypes.c_uint32),
        ("nr_map_ids", ctypes.c_uint32),
        ("map_ids", ctypes.c_uint64),
        ("name", ctypes.c_char * BPF_OBJ_NAME_LEN),
        ("ifindex", ctypes.c_uint32),
        ("gpl_compatible", ctypes.c_uint32, 1),
        ("_bitfield_pad", ctypes.c_uint32, 31),
        ("netns_dev", ctypes.c_uint64),
        ("netns_ino", ctypes.c_uint64),
        ("nr_jited_ksyms", ctypes.c_uint32),
        ("nr_jited_func_lens", ctypes.c_uint32),
        ("jited_ksyms", ctypes.c_uint64),
        ("jited_func_lens", ctypes.c_uint64),
        ("btf_id", ctypes.c_uint32),
        ("func_info_rec_size", ctypes.c_uint32),
        ("func_info", ctypes.c_uint64),
        ("nr_func_info", ctypes.c_uint32),
        ("nr_line_info", ctypes.c_uint32),
        ("line_info", ctypes.c_uint64),
        ("jited_line_info", ctypes.c_uint64),
        ("nr_jited_line_info", ctypes.c_uint32),
        ("line_info_rec_size", ctypes.c_uint32),
        ("jited_line_info_rec_size", ctypes.c_uint32),
        ("nr_prog_tags", ctypes.c_uint32),
        ("prog_tags", ctypes.c_uint64),
        ("run_time_ns", ctypes.c_uint64),
        ("run_cnt", ctypes.c_uint64),
        ("recursion_misses", ctypes.c_uint64),
        ("verified_insns", ctypes.c_uint32),
        ("attach_btf_obj_id", ctypes.c_uint32),
        ("attach_btf_id", ctypes.c_uint32),
    ]


class Libbpf:
    def __init__(self) -> None:
        path = ctypes.util.find_library("bpf") or "libbpf.so.1"
        self.lib = ctypes.CDLL(path, use_errno=True)
        self.lib.bpf_object__open_file.argtypes = [ctypes.c_char_p, ctypes.c_void_p]
        self.lib.bpf_object__open_file.restype = ctypes.c_void_p
        self.lib.bpf_object__close.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__close.restype = None
        self.lib.bpf_object__next_program.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
        self.lib.bpf_object__next_program.restype = ctypes.c_void_p
        self.lib.bpf_program__name.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__name.restype = ctypes.c_char_p
        self.lib.bpf_program__set_autoload.argtypes = [ctypes.c_void_p, ctypes.c_bool]
        self.lib.bpf_program__set_autoload.restype = ctypes.c_int
        self.lib.bpf_object__load.argtypes = [ctypes.c_void_p]
        self.lib.bpf_object__load.restype = ctypes.c_int
        self.lib.bpf_program__attach.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__attach.restype = ctypes.c_void_p
        self.lib.bpf_program__fd.argtypes = [ctypes.c_void_p]
        self.lib.bpf_program__fd.restype = ctypes.c_int
        self.lib.bpf_link__destroy.argtypes = [ctypes.c_void_p]
        self.lib.bpf_link__destroy.restype = ctypes.c_int
        self.lib.libbpf_get_error.argtypes = [ctypes.c_void_p]
        self.lib.libbpf_get_error.restype = ctypes.c_long
        self.lib.bpf_enable_stats.argtypes = [ctypes.c_int]
        self.lib.bpf_enable_stats.restype = ctypes.c_int
        self.lib.bpf_prog_get_info_by_fd.argtypes = [
            ctypes.c_int,
            ctypes.POINTER(BpfProgInfo),
            ctypes.POINTER(ctypes.c_uint32),
        ]
        self.lib.bpf_prog_get_info_by_fd.restype = ctypes.c_int

    def pointer_error(self, ptr: ctypes.c_void_p | int | None) -> int:
        return int(self.lib.libbpf_get_error(ctypes.c_void_p(ptr or 0)))

    def enable_stats(self) -> int:
        fd = int(self.lib.bpf_enable_stats(BPF_STATS_RUN_TIME))
        if fd < 0:
            err = ctypes.get_errno()
            raise ManualTraceeLoadError(f"bpf_enable_stats failed: {os.strerror(err)} (errno={err})")
        return fd

    def get_prog_info(self, prog_fd: int) -> BpfProgInfo:
        info = BpfProgInfo()
        info_len = ctypes.c_uint32(ctypes.sizeof(info))
        rc = self.lib.bpf_prog_get_info_by_fd(prog_fd, ctypes.byref(info), ctypes.byref(info_len))
        if rc != 0:
            err = ctypes.get_errno()
            raise ManualTraceeLoadError(
                f"bpf_prog_get_info_by_fd failed: {os.strerror(err)} (errno={err})"
            )
        return info


def decode_program_name(raw_name: bytes | str) -> str:
    if isinstance(raw_name, bytes):
        return raw_name.split(b"\0", 1)[0].decode("utf-8", "replace")
    return str(raw_name)


def snapshot_from_info(info: BpfProgInfo) -> ProgramSnapshot:
    return ProgramSnapshot(
        prog_id=int(info.id),
        run_cnt=int(info.run_cnt),
        run_time_ns=int(info.run_time_ns),
        bytes_xlated=int(info.xlated_prog_len),
        bytes_jited=int(info.jited_prog_len),
        prog_name=decode_program_name(bytes(info.name)),
    )


class ManualTraceeSession:
    # Retain the live manual-fallback loader without keeping the legacy standalone CLI harness.
    def __init__(self, libbpf: Libbpf, object_path: Path, selected: Sequence[ProgramInventoryEntry]) -> None:
        self.libbpf = libbpf
        self.object_path = object_path
        self.selected = {entry.name: entry for entry in selected}
        self.object_ptr: int | None = None
        self.stats_fd = -1
        self.program_handles: dict[str, ProgramHandle] = {}

    def __enter__(self) -> "ManualTraceeSession":
        try:
            self.stats_fd = self.libbpf.enable_stats()
            object_ptr = self.libbpf.lib.bpf_object__open_file(str(self.object_path).encode(), None)
            open_error = self.libbpf.pointer_error(object_ptr)
            if open_error != 0:
                raise ManualTraceeLoadError(f"bpf_object__open_file failed: errno={open_error}")
            self.object_ptr = int(object_ptr)

            program_ptrs: dict[str, int] = {}
            current_ptr = ctypes.c_void_p()
            while True:
                current_ptr = ctypes.c_void_p(self.libbpf.lib.bpf_object__next_program(self.object_ptr, current_ptr))
                if not current_ptr.value:
                    break
                name = decode_program_name(self.libbpf.lib.bpf_program__name(current_ptr))
                keep = name in self.selected
                rc = self.libbpf.lib.bpf_program__set_autoload(current_ptr, keep)
                if rc != 0:
                    raise ManualTraceeLoadError(f"bpf_program__set_autoload failed for {name}: rc={rc}")
                if keep:
                    program_ptrs[name] = int(current_ptr.value)

            missing = sorted(set(self.selected) - set(program_ptrs))
            if missing:
                raise ManualTraceeLoadError(f"manual selection missing programs: {', '.join(missing)}")

            rc = self.libbpf.lib.bpf_object__load(self.object_ptr)
            if rc != 0:
                raise ManualTraceeLoadError(f"bpf_object__load failed: rc={rc}")

            for name, entry in self.selected.items():
                program_ptr = program_ptrs[name]
                prog_fd = int(self.libbpf.lib.bpf_program__fd(program_ptr))
                if prog_fd < 0:
                    import sys
                    print(f"[manual] WARNING: bpf_program__fd failed for {name}, skipping", file=sys.stderr)
                    continue
                link_ptr = self.libbpf.lib.bpf_program__attach(program_ptr)
                attach_error = self.libbpf.pointer_error(link_ptr)
                if attach_error != 0:
                    import sys
                    print(f"[manual] WARNING: bpf_program__attach failed for {name}: errno={attach_error}, skipping", file=sys.stderr)
                    continue
                info = self.libbpf.get_prog_info(prog_fd)
                self.program_handles[name] = ProgramHandle(
                    name=name,
                    section_name=entry.section_name,
                    prog_type_name=entry.prog_type_name,
                    prog_fd=prog_fd,
                    prog_id=int(info.id),
                    link_ptr=int(link_ptr),
                )
            if not self.program_handles:
                raise ManualTraceeLoadError("no programs could be attached")
            return self
        except Exception:
            self.__exit__(None, None, None)
            raise

    def snapshot(self) -> dict[str, ProgramSnapshot]:
        return {
            name: snapshot_from_info(self.libbpf.get_prog_info(handle.prog_fd))
            for name, handle in self.program_handles.items()
        }

    def __exit__(self, exc_type, exc, tb) -> None:
        for handle in self.program_handles.values():
            if handle.link_ptr:
                self.libbpf.lib.bpf_link__destroy(handle.link_ptr)
        self.program_handles.clear()
        if self.stats_fd >= 0:
            os.close(self.stats_fd)
            self.stats_fd = -1
        if self.object_ptr:
            self.libbpf.lib.bpf_object__close(self.object_ptr)
            self.object_ptr = None
