from __future__ import annotations

import io
import os
import shutil
import subprocess
import tempfile
import threading
from collections import deque
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Mapping, Sequence

import yaml

from .. import ROOT_DIR, tail_text, which
from ..agent import stop_agent
from ..workload import WorkloadResult, run_named_workload
from .base import AppRunner
from .process_support import wait_for_attached_programs

DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "bcc" / "config.yaml"
DEFAULT_ATTACH_TIMEOUT_SECONDS = 20
DEFAULT_MIN_BIOSNOOP_CORPUS_RUNS = 100
KHEADERS_READY_MARKER = ".bpfrejit-kheaders-ready"
BCC_COMPAT_CFLAGS_ENV = "BPFREJIT_BCC_EXTRA_CFLAGS"
BCC_PYTHON_COMPAT_DIR_PREFIX = "bcc-python-"

BCC_COMPAT_HEADER = r"""
#ifndef BPFREJIT_BCC_COMPAT_H
#define BPFREJIT_BCC_COMPAT_H

/*
 * Ubuntu's BCC 0.29 ships an embedded UAPI bpf.h. Newer benchmark kernels can
 * include private headers that expect UAPI constants added after that snapshot.
 */
#ifndef BPF_LOAD_ACQ
#define BPF_LOAD_ACQ 0x100
#endif
#ifndef BPF_STORE_REL
#define BPF_STORE_REL 0x110
#endif
#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#define BPFREJIT_BCC_NEEDS_KINSN_UAPI_COMPAT 1
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif
#ifndef BPF_F_CPU
#define BPF_F_CPU 8
#endif
#ifndef BPF_F_ALL_CPUS
#define BPF_F_ALL_CPUS 16
#endif
#ifndef BPF_TRACE_FSESSION
#define BPF_TRACE_FSESSION (__MAX_BPF_ATTACH_TYPE + 14)
#endif
#ifdef BPFREJIT_BCC_NEEDS_KINSN_UAPI_COMPAT
struct bpf_task_work {
	__u64 __opaque;
} __attribute__((aligned(8)));
struct bpf_wq {
	__u64 __opaque[2];
} __attribute__((aligned(8)));
#endif

/*
 * BCC tools only need struct ns_common layout data. Avoid compiling helper
 * inlines that depend on kernel-only namespace-tree fields and trip clang.
 */
#include <linux/ns/ns_common_types.h>
#ifndef _LINUX_NS_COMMON_H
#define _LINUX_NS_COMMON_H
#endif
#ifndef ns_ref_read
#define ns_ref_read(__ns) 0
#endif
#ifndef ns_ref_inc
#define ns_ref_inc(__ns) do { } while (0)
#endif
#ifndef ns_ref_get
#define ns_ref_get(__ns) ((__ns) != 0)
#endif
#ifndef ns_ref_put
#define ns_ref_put(__ns) 0
#endif
#ifndef ns_ref_put_and_lock
#define ns_ref_put_and_lock(__ns, __ns_lock) 0
#endif
#ifndef ns_ref_active_read
#define ns_ref_active_read(__ns) 0
#endif
#ifndef ns_ref_active_get
#define ns_ref_active_get(__ns) do { } while (0)
#endif
#ifndef ns_ref_active_put
#define ns_ref_active_put(__ns) do { } while (0)
#endif

/*
 * BPF probe compilation includes kernel internals in isolation. Layout asserts
 * that are valid during a full kernel build can be false in BCC's reduced view.
 */
#include <linux/build_bug.h>
#undef static_assert
#define static_assert(expr, ...) /* BCC reduced-header compatibility */

#endif
""".lstrip()

BCC_SITE_CUSTOMIZE = r"""
import os

try:
    import bcc as _bcc
except Exception:
    _bcc = None

if _bcc is not None and not getattr(_bcc.BPF, "_bpfrejit_cflags_patched", False):
    _bpfrejit_original_init = _bcc.BPF.__init__

    def _bpfrejit_init(self, *args, **kwargs):
        cflags = list(kwargs.get("cflags") or [])
        for flag in os.environ.get("BPFREJIT_BCC_EXTRA_CFLAGS", "").splitlines():
            if flag and flag not in cflags:
                cflags.append(flag)
        kwargs["cflags"] = cflags
        return _bpfrejit_original_init(self, *args, **kwargs)

    _bcc.BPF.__init__ = _bpfrejit_init
    _bcc.BPF._bpfrejit_cflags_patched = True
""".lstrip()


def _tool_binary_names(tool_name: str) -> tuple[str, ...]:
    normalized = str(tool_name).strip()
    if not normalized:
        return ()
    if normalized.endswith("-bpfcc"):
        return (normalized,)
    return (f"{normalized}-bpfcc", normalized)


@dataclass(frozen=True)
class BCCWorkloadSpec:
    name: str
    workload_kind: str
    expected_programs: int
    spawn_timeout_s: int
    tool_args: tuple[str, ...]


@dataclass
class ToolProcessSession:
    process: subprocess.Popen[str]
    stdout_capture: "_TailCapture"
    stderr_capture: "_TailCapture"
    stdout_thread: threading.Thread
    stderr_thread: threading.Thread


class _TailCapture:
    def __init__(self, *, max_lines: int, max_chars: int) -> None:
        self.max_lines = max(1, int(max_lines))
        self.max_chars = max(1, int(max_chars))
        self._chunks: deque[str] = deque()
        self._chars = 0
        self._lock = threading.Lock()

    def append(self, text: str) -> None:
        if not text:
            return
        with self._lock:
            self._chunks.append(text)
            self._chars += len(text)
            while self._chars > self.max_chars and self._chunks:
                removed = self._chunks.popleft()
                self._chars -= len(removed)

    def render(self) -> str:
        with self._lock:
            return tail_text("".join(self._chunks), max_lines=self.max_lines, max_chars=self.max_chars)


def _drain_stream(stream: io.TextIOBase, capture: _TailCapture) -> None:
    with stream:
        for chunk in stream:
            capture.append(chunk)


@lru_cache(maxsize=1)
def _bcc_tool_specs() -> dict[str, BCCWorkloadSpec]:
    payload = yaml.safe_load(DEFAULT_CONFIG.read_text(encoding="utf-8"))
    if not isinstance(payload, Mapping):
        raise RuntimeError(f"BCC config must be a mapping: {DEFAULT_CONFIG}")
    tools = payload.get("tools")
    if not isinstance(tools, list):
        raise RuntimeError(f"BCC config field 'tools' must be a sequence: {DEFAULT_CONFIG}")
    specs: dict[str, BCCWorkloadSpec] = {}
    for entry in tools:
        if not isinstance(entry, Mapping):
            raise RuntimeError(f"BCC config field 'tools' contains a non-mapping entry: {DEFAULT_CONFIG}")
        name = str(entry.get("name") or "").strip()
        if not name:
            raise RuntimeError(f"BCC config field 'tools' contains an entry without a name: {DEFAULT_CONFIG}")
        specs[name] = BCCWorkloadSpec(
            name=name,
            workload_kind=str(entry.get("workload_kind") or "mixed"),
            expected_programs=int(entry.get("expected_programs", 1) or 1),
            spawn_timeout_s=int(entry.get("spawn_timeout_s", DEFAULT_ATTACH_TIMEOUT_SECONDS) or DEFAULT_ATTACH_TIMEOUT_SECONDS),
            tool_args=tuple(str(arg) for arg in entry.get("tool_args", []) if str(arg).strip()),
        )
    return specs


def inspect_bcc_setup() -> dict[str, object]:
    resolved_tools: dict[str, str] = {}
    for tool_name in _bcc_tool_specs():
        resolved = next((path for name in _tool_binary_names(tool_name) if (path := which(name)) is not None), None)
        if resolved is None:
            return {
                "returncode": 1,
                "tools_dir": None,
                "stdout_tail": "",
                "stderr_tail": f"missing distro BCC tool for {tool_name}; install bpfcc-tools and python3-bpfcc",
            }
        resolved_tools[tool_name] = resolved

    tool_dirs = sorted({str(Path(path).parent) for path in resolved_tools.values()})

    return {
        "returncode": 0,
        "tools_dir": os.pathsep.join(tool_dirs),
        "stdout_tail": "\n".join(f"BCC_TOOL_{name}={path}" for name, path in sorted(resolved_tools.items())),
        "stderr_tail": "",
    }


def resolve_tools_dir(
    explicit: str | Path | None = None,
    *,
    setup_result: Mapping[str, object] | None = None,
) -> Path:
    if explicit:
        candidate = Path(explicit)
        if candidate.is_dir():
            return candidate.resolve()
    setup_dir = str((setup_result or {}).get("tools_dir") or "").strip()
    if setup_dir:
        for item in setup_dir.split(os.pathsep):
            candidate = Path(item)
            if candidate.is_dir():
                return candidate.resolve()
    return Path("/usr/sbin")


def find_tool_binary(tools_dir: Path, tool_name: str) -> Path | None:
    for binary_name in _tool_binary_names(tool_name):
        resolved = which(binary_name)
        if resolved is not None:
            return Path(resolved).resolve()
        for candidate in (tools_dir / binary_name, tools_dir.parent / binary_name):
            if candidate.is_file() and os.access(candidate, os.X_OK):
                return candidate.resolve()
    return None


def _prepare_bcc_kernel_source(env: dict[str, str]) -> str | None:
    explicit = env.get("BCC_KERNEL_SOURCE", "").strip()
    if explicit:
        candidate = Path(explicit)
        if candidate.is_dir():
            return str(candidate)

    release = os.uname().release
    kernel_build_dir = Path("/lib/modules") / release / "build"
    if kernel_build_dir.exists():
        return None

    kheaders_tar = Path("/sys/kernel/kheaders.tar.xz")
    if not kheaders_tar.exists():
        subprocess.run(["modprobe", "kheaders"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=False)
    if not kheaders_tar.exists():
        return None

    tmp_root = Path(env.get("BPFREJIT_RUNTIME_TMPDIR") or env.get("TMPDIR") or "/tmp")
    target = tmp_root / "bcc-kheaders" / release
    marker = target / KHEADERS_READY_MARKER
    if not marker.exists():
        staging = target.parent / f".{target.name}.tmp"
        shutil.rmtree(staging, ignore_errors=True)
        staging.mkdir(parents=True, exist_ok=True)
        completed = subprocess.run(
            ["tar", "--no-same-owner", "--no-same-permissions", "-C", str(staging), "-xf", str(kheaders_tar)],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=False,
        )
        if completed.returncode != 0:
            details = tail_text(completed.stderr or completed.stdout or "")
            raise RuntimeError(f"failed to extract BCC kernel headers from {kheaders_tar}: {details}")
        shutil.rmtree(target, ignore_errors=True)
        staging.rename(target)
        marker.write_text("ok\n", encoding="utf-8")

    env["BCC_KERNEL_SOURCE"] = str(target)
    return str(target)


def _prepare_bcc_python_compat(env: dict[str, str]) -> Path:
    tmp_root = Path(env.get("BPFREJIT_RUNTIME_TMPDIR") or env.get("TMPDIR") or "/tmp")
    tmp_root.mkdir(parents=True, exist_ok=True)
    compat_dir = Path(tempfile.mkdtemp(prefix=BCC_PYTHON_COMPAT_DIR_PREFIX, dir=str(tmp_root)))
    header = compat_dir / "bpfrejit_bcc_compat.h"
    sitecustomize = compat_dir / "sitecustomize.py"
    header.write_text(BCC_COMPAT_HEADER, encoding="utf-8")
    sitecustomize.write_text(BCC_SITE_CUSTOMIZE, encoding="utf-8")

    env[BCC_COMPAT_CFLAGS_ENV] = "\n".join(("-include", str(header)))
    pythonpath = env.get("PYTHONPATH", "")
    env["PYTHONPATH"] = str(compat_dir) if not pythonpath else str(compat_dir) + os.pathsep + pythonpath
    return compat_dir


class BCCRunner(AppRunner):
    def __init__(
        self,
        *,
        tool_binary: Path | str | None = None,
        tool_name: str | None = None,
        tool_args: Sequence[str] | None = None,
        workload_kind: str | None = None,
        expected_programs: int | None = None,
        expected_program_names: Sequence[str] = (),
        attach_timeout_s: int | None = None,
        tools_dir: Path | str | None = None,
    ) -> None:
        super().__init__()
        resolved_tool_name = str(tool_name or "").strip()
        if not resolved_tool_name and tool_binary is None:
            raise RuntimeError("BCCRunner requires tool_binary or tool_name")

        spec = _bcc_tool_specs().get(resolved_tool_name)
        self.tool_name = resolved_tool_name or Path(str(tool_binary)).name
        self.tool_args = (
            tuple(str(arg) for arg in tool_args if str(arg).strip())
            if tool_args is not None
            else (spec.tool_args if spec else ())
        )
        self.workload_kind = workload_kind or (spec.workload_kind if spec else "mixed")
        self.expected_programs = int(expected_programs or (spec.expected_programs if spec else max(1, len(tuple(expected_program_names)) or 1)))
        self.attach_timeout_s = int(attach_timeout_s or (spec.spawn_timeout_s if spec else DEFAULT_ATTACH_TIMEOUT_SECONDS))
        self.expected_program_names = tuple(str(name) for name in expected_program_names if str(name).strip())
        self.setup_result: dict[str, object] = {
            "returncode": 0,
            "tools_dir": None,
            "stdout_tail": "",
            "stderr_tail": "",
        }
        self.explicit_tools_dir = Path(tools_dir).resolve() if tools_dir is not None else None
        self.tools_dir = resolve_tools_dir(self.explicit_tools_dir)
        self.tool_binary = Path(tool_binary).resolve() if tool_binary is not None else None
        self.session: ToolProcessSession | None = None
        self._compat_dir: Path | None = None

    @property
    def pid(self) -> int | None:
        return None if self.session is None else int(self.session.process.pid or 0)

    def _resolve_tool_binary(self) -> Path:
        if self.tool_binary is not None:
            if not self.tool_binary.exists():
                raise RuntimeError(f"BCC tool binary not found: {self.tool_binary}")
            if not os.access(self.tool_binary, os.X_OK):
                raise RuntimeError(f"BCC tool binary is not executable: {self.tool_binary}")
            return self.tool_binary

        self.setup_result = inspect_bcc_setup()
        if int(self.setup_result.get("returncode", 0) or 0) != 0:
            stderr_tail = str(self.setup_result.get("stderr_tail") or "")
            raise RuntimeError(f"BCC setup failed: {stderr_tail or self.setup_result}")
        self.tools_dir = resolve_tools_dir(self.explicit_tools_dir, setup_result=self.setup_result)

        tool_binary = find_tool_binary(self.tools_dir, self.tool_name)
        if tool_binary is None:
            raise RuntimeError(f"BCC tool '{self.tool_name}' not found in {self.tools_dir}")
        self.tool_binary = tool_binary
        return tool_binary

    def start(self) -> list[int]:
        if self.session is not None:
            raise RuntimeError(f"BCC tool {self.tool_name} is already running")

        tool_binary = self._resolve_tool_binary()
        tool_env = os.environ.copy()
        kernel_source = _prepare_bcc_kernel_source(tool_env)
        if kernel_source:
            self.artifacts["bcc_kernel_source"] = kernel_source
        self._compat_dir = _prepare_bcc_python_compat(tool_env)
        self.artifacts["bcc_python_compat_dir"] = str(self._compat_dir)
        command = [str(tool_binary), *self.tool_args]
        self.command_used = list(command)
        process = subprocess.Popen(
            command,
            cwd=ROOT_DIR,
            env=tool_env,
            stdin=subprocess.DEVNULL,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        if process.stdout is None or process.stderr is None:
            process.kill()
            raise RuntimeError(f"BCC tool {self.tool_name} did not expose stdout/stderr pipes")
        stdout_capture = _TailCapture(max_lines=40, max_chars=8000)
        stderr_capture = _TailCapture(max_lines=40, max_chars=8000)
        stdout_thread = threading.Thread(
            target=_drain_stream,
            args=(process.stdout, stdout_capture),
            daemon=True,
        )
        stderr_thread = threading.Thread(
            target=_drain_stream,
            args=(process.stderr, stderr_capture),
            daemon=True,
        )
        stdout_thread.start()
        stderr_thread.start()
        self.session = ToolProcessSession(
            process=process,
            stdout_capture=stdout_capture,
            stderr_capture=stderr_capture,
            stdout_thread=stdout_thread,
            stderr_thread=stderr_thread,
        )
        programs = wait_for_attached_programs(
            process,
            expected_count=self.expected_programs,
            timeout_s=self.attach_timeout_s,
        )
        if not programs:
            return self._fail_start(
                f"BCC tool {self.tool_name} did not attach any BPF programs within {self.attach_timeout_s}s"
            )
        if len(programs) < self.expected_programs:
            attached_names = sorted(str(program.get("name") or "") for program in programs if str(program.get("name") or "").strip())
            return self._fail_start(
                f"BCC tool {self.tool_name} attached {len(programs)} programs, expected at least {self.expected_programs}: {attached_names}"
            )

        if self.expected_program_names:
            programs = self._filter_expected_programs(
                programs,
                self.expected_program_names,
                owner_label=f"BCC tool {self.tool_name}",
            )

        self.programs = [dict(program) for program in programs]
        return [int(program["id"]) for program in self.programs if int(program.get("id", 0) or 0) > 0]

    def run_workload(self, seconds: float) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"BCC tool {self.tool_name} is not running")
        return run_named_workload(self.workload_kind, seconds, network_as_tcp_connect=True)

    def run_workload_spec(
        self,
        workload_spec: Mapping[str, object],
        seconds: float,
    ) -> WorkloadResult:
        if self.session is None:
            raise RuntimeError(f"BCC tool {self.tool_name} is not running")
        requested_kind = str(workload_spec.get("kind") or workload_spec.get("name") or "").strip()
        if not requested_kind:
            raise RuntimeError(f"BCC tool {self.tool_name} workload spec is missing a workload kind")
        return run_named_workload(requested_kind, seconds, network_as_tcp_connect=True)

    def select_corpus_program_ids(
        self,
        initial_stats: Mapping[int, Mapping[str, object]],
        final_stats: Mapping[int, Mapping[str, object]],
    ) -> list[int] | None:
        selected = super().select_corpus_program_ids(initial_stats, final_stats)
        if self.tool_name != "biosnoop" or not selected:
            return selected
        min_runs = int(os.environ.get("BPFREJIT_BCC_BIOSNOOP_MIN_CORPUS_RUNS", DEFAULT_MIN_BIOSNOOP_CORPUS_RUNS))
        stable: list[int] = []
        for prog_id in selected:
            before = initial_stats.get(int(prog_id)) or {}
            after = final_stats.get(int(prog_id)) or {}
            run_cnt_delta = int(after.get("run_cnt", 0) or 0) - int(before.get("run_cnt", 0) or 0)
            if run_cnt_delta >= max(1, min_runs):
                stable.append(int(prog_id))
        return stable or selected

    def stop(self) -> None:
        if self.session is None:
            return
        session = self.session
        self.session = None
        stop_error: Exception | None = None
        try:
            stop_agent(session.process, timeout=8)
        except Exception as exc:
            stop_error = exc

        io_errors: list[str] = []
        for name, thread in (("stdout", session.stdout_thread), ("stderr", session.stderr_thread)):
            thread.join(timeout=2.0)
            if thread.is_alive():
                io_errors.append(f"timed out waiting for BCC {name} capture thread to drain")
        self.process_output = {
            "returncode": session.process.returncode,
            "stdout_tail": session.stdout_capture.render(),
            "stderr_tail": session.stderr_capture.render(),
        }
        if self._compat_dir is not None:
            shutil.rmtree(self._compat_dir, ignore_errors=True)
            self._compat_dir = None

        failures: list[str] = []
        if stop_error is not None:
            failures.append(str(stop_error))
        failures.extend(io_errors)
        if failures:
            raise RuntimeError("; ".join(failures))
